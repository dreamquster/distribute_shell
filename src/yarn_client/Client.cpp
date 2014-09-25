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

	} while (!done);


}

void RpcSASLClient::send_sasl_message(RpcSaslProto& message) {
	YarnRpcRequest request(&SASL_HEADER, &message);
	
	int request_len = request.get_length();
	if (0 < request_len) {
		send(m_sasl_server_fd, request.c_str(), request_len, 0);		
	}	
}