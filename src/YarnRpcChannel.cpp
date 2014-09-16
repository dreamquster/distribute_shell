#include "YarnRpcChannel.h"
#include "yarn_protocal/RpcHeader.pb.h"
#include "yarn_protocal/ProtobufRpcEngine.pb.h"
#include "yarn_protocal/applicationclient_protocol.pb.h"

using namespace hadoop::common;


YarnRpcChannel::YarnRpcChannel(void)
{
}


YarnRpcChannel::~YarnRpcChannel(void)
{
}

void YarnRpcChannel::CallMethod(const MethodDescriptor* method, RpcController* controller, 
	const Message* request, Message* response, Closure* done) {
		RequestHeaderProto requst_header;
		const char* PROTOCAL_NAME = "org.apache.hadoop.yarn.api.ApplicationClientProtocolPB";
		const int CLIENT_PROTOCAL_VERSION = 1;
		requst_header.set_methodname(method->name());
		requst_header.set_declaringclassprotocolname(PROTOCAL_NAME);
		requst_header.set_clientprotocolversion(CLIENT_PROTOCAL_VERSION);

		RpcRequestHeaderProto rpc_request_header;
		rpc_request_header.set_rpckind(RPC_PROTOCOL_BUFFER);
		rpc_request_header.set_rpcop(RpcRequestHeaderProto_OperationProto_RPC_FINAL_PACKET);
		rpc_request_header.set_callid(method->index());
		rpc_request_header.set_retrycount(1);

		






}
