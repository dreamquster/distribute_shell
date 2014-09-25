#include "Client.h"
#include "const_variable.h"
#include "utils/ProtobufUtils.h"
const Logger RpcSASLClient::LOG = Logger::getInstance(LOG4CPLUS_TEXT("RpcSASLClient"));

namespace {
	static RpcRequestHeaderProto SASL_HEADER = ProtobufUtils::make_rpc_request_header(
		RPC_PROTOCOL_BUFFER, RPC_FINAL_PACKET, RpcConstant::SASL_CALLID, 
		RpcConstant::INVALID_TRIES, "");

	inline RpcSaslProto init_negotiate(void) {
		RpcSaslProto request;
		request.set_state(RpcSaslProto_SaslState_NEGOTIATE);
		return request;
	}

	static RpcSaslProto NEGOTIATE_REQUEST = init_negotiate();
}

RpcSASLClient::RpcSASLClient(int& remote_server) {

}


RpcSASLClient::~RpcSASLClient(void) {

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

		switch(sasl_message.state()) {
		case RpcSaslProto_SaslState_NEGOTIATE:

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
	sasl_message.auths()
}

void RpcSASLClient::create_sasl_client(RpcSaslProto& sasl_message) {
	int auth_sizes = sasl_message.auths_size();
	for (int i = 0; i < auth_sizes; ++i) {
		const RpcSaslProto_SaslAuth& auth_type = sasl_message.auths(i);
		const string& auth_method =  auth_type.method();
		if (auth_method != RpcConstant::AUTH_SIMPLE) {

		}
	}
}

void RpcSASLClient::init_sasl_client_by_authtype(const RpcSaslProto_SaslAuth& auth_type) {
	const string& sasl_protocol = auth_type.protocol();
	const string& server_id = auth_type.serverid();
	const string& auth_method = auth_type.method();
	const string& mechanism = auth_type.mechanism();

	if (auth_method == "TOKEN") {
		const Token* token = UserGroupInformation::get_service_token(server_id);

		sasl_client_new(server_id.c_str())
	}

	
}

void RpcSASLClient::select_token(const string& service_name) {
	


}