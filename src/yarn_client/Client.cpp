#include "Client.h"
#include "utils/const_variable.h"
#include "utils/ProtobufUtils.h"
#include "utils/SASLClient.h"
#include "yarn_protocal/RpcHeader.pb.h"
#include "UserGroupInformation.h"
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>


using namespace hadoop::common;

const Logger RpcSASLClient::LOG = Logger::getInstance(LOG4CPLUS_TEXT("RpcSASLClient"));
typedef int(*SASL_PROC)(void) ; 

namespace {
	static RpcRequestHeaderProto SASL_HEADER = ProtobufUtils::make_rpc_request_header(
		RPC_PROTOCOL_BUFFER, RpcRequestHeaderProto::RPC_FINAL_PACKET, RpcConstant::SASL_CALLID, 
		RpcConstant::INVALID_TRIES, "");

	inline RpcSaslProto init_negotiate(void) {
		RpcSaslProto request;
		request.set_state(RpcSaslProto_SaslState_NEGOTIATE);
		return request;
	}

	static RpcSaslProto NEGOTIATE_REQUEST = init_negotiate();


	

	/* callbacks we support */
	static const sasl_callback_t callbacks[] = {
		{
			SASL_CB_GETREALM, (SASL_PROC)(&getrealm), NULL
		}, {
			SASL_CB_USER, (SASL_PROC)(&simple), NULL
		}, {
			SASL_CB_AUTHNAME, (SASL_PROC)(&simple), NULL
			}, {
				SASL_CB_PASS, (SASL_PROC)(&getsecret), NULL
			}, {
				SASL_CB_GETPATH, (SASL_PROC)(&getpath), NULL
			}, {
				SASL_CB_LIST_END, NULL, NULL
				}
	};
}

RpcSASLClient::RpcSASLClient(int& remote_server) {
	m_sasl_server_fd = remote_server;
	m_sasl_conn = NULL;
}


RpcSASLClient::~RpcSASLClient(void) {
	if (m_sasl_conn) {
		delete m_sasl_conn;
	}
}

void RpcSASLClient::sasl_connect() {
	send_sasl_message(NEGOTIATE_REQUEST);

	bool done = false;
	do {
		RpcResponseHeaderProto header;
		RpcSaslProto sasl_message;
		NetUtils::receive_rpc_response(m_sasl_server_fd, header, sasl_message);

		if (header.status() == RpcResponseHeaderProto_RpcStatusProto_ERROR
			|| RpcResponseHeaderProto_RpcStatusProto_FATAL == header.status()) {
				LOG4CPLUS_ERROR(LOG, "connect to sasl happened expcetion"<< header.exceptionclassname()
					<<" error message:"<<header.errormsg());
				break;
		}

		RpcSaslProto sasl_msg_response;
		switch(sasl_message.state()) {
		case RpcSaslProto_SaslState_NEGOTIATE:
			const RpcSaslProto_SaslAuth& auth_type = create_sasl_client(sasl_message);
			const string& challenge_token = auth_type.challenge();

			if (!challenge_token.empty()) {
				char* response_challege = NULL;
				int resp_challege_len = 0;
				sasl_checkapop(m_sasl_conn, challenge_token.c_str(), challenge_token.length(), 
					response_challege, &response_challege);
			}

			string response_token;

			sasl_msg_response.set_state(RpcSaslProto_SaslState_INITIATE);
			RpcSaslProto_SaslAuth* new_auth = sasl_msg_response.add_auths();
			sasl_msg_response.set_token(challenge_token);			
			new_auth->CopyFrom(auth_type);
			
			
			break;
		case RpcSaslProto_SaslState_CHALLENGE:
			break;
		case RpcSaslProto_SaslState_SUCCESS:
			break;
		default:
			break;
		}

	} while (!done);


}




void RpcSASLClient::send_sasl_message(RpcSaslProto& message) {
	YarnRpcRequest request(&SASL_HEADER, &message);
	
	int request_len = request.get_length();
	if (0 < request_len) {
		send(m_sasl_server_fd, request.c_str(), request_len, 0);		
	}	
}

RpcSaslProto RpcSASLClient::get_init_sasl_response(RpcSaslProto& sasl_message) {
	RpcSaslProto response;
}

const RpcSaslProto_SaslAuth&  RpcSASLClient::create_sasl_client(RpcSaslProto& sasl_message) {
	int auth_sizes = sasl_message.auths_size();
	for (int i = 0; i < auth_sizes; ++i) {
		const RpcSaslProto_SaslAuth& auth_type = sasl_message.auths(i);
		const string& auth_method =  auth_type.method();
		if (auth_method == RpcConstant::AUTH_TOKEN) {
			init_sasl_client_by_authtype(auth_type);
			return auth_type;
		}
	}
}

void RpcSASLClient::init_sasl_client_by_authtype(const RpcSaslProto_SaslAuth& auth_type) {
	const string& sasl_protocol = auth_type.protocol();
	const string& server_id = auth_type.serverid();
	const string& auth_method = auth_type.method();
	const string& mechanism = auth_type.mechanism();

	if (auth_method == RpcConstant::AUTH_TOKEN) {
		const Token* token = UserGroupInformation::get_service_token(server_id);

		const char* host = "localhost";
		sockaddr_storage local_ip;
		sockaddr_storage remote_ip;
		int len = sizeof(local_ip);
		if (getsockname(m_sasl_server_fd, (sockaddr*)&local_ip, &len)) {
			LOG4CPLUS_ERROR(LOG, "can not get sock name of " << m_sasl_server_fd);
			return;
		}

		char hbuf[NI_MAXHOST] = {0};
		char pbuf[NI_MAXSERV] = {0};
		char localaddr[NI_MAXHOST + NI_MAXSERV] = {0};
		char remoteaddr[NI_MAXHOST + NI_MAXSERV] = {0};

		getnameinfo((sockaddr*)&local_ip, sizeof(local_ip),
			hbuf, sizeof(hbuf), pbuf, sizeof(pbuf), 
			NI_NUMERICHOST | NI_NUMERICSERV);
		snprintf(localaddr, sizeof(localaddr), "%s;%s", hbuf, pbuf);

		len = sizeof(remote_ip);
		if (getpeername(m_sasl_server_fd, (sockaddr*)&remote_ip, &len)) {
			LOG4CPLUS_ERROR(LOG, "can not getpeername of " << m_sasl_server_fd);
			return;
		}

		getnameinfo((sockaddr*)&remote_ip, sizeof(remote_ip),
			hbuf, sizeof(hbuf), pbuf, sizeof(pbuf), 
			NI_NUMERICHOST | NI_NUMERICSERV);
		snprintf(remoteaddr, sizeof(remoteaddr), "%s;%s", hbuf, pbuf);

		int ret = sasl_client_init(callbacks);
		if (SASL_OK != ret) {
			LOG4CPLUS_ERROR(LOG, ret <<  "can not init SASL client callback");
		}

		ret = sasl_client_new(server_id.c_str(), host, localaddr,
			remoteaddr, NULL, 0, m_sasl_conn);
		if (SASL_OK != ret) {
			LOG4CPLUS_ERROR(LOG, ret <<  "allocating connection state");
		}

		/*int sock_in = fdopen(m_sasl_server_fd, "r");
		int sock_out = fdopen(m_sasl_server_fd, "w");*/

		
	}

	
}

void RpcSASLClient::select_token(const string& service_name) {
	


}