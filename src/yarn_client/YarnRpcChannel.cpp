#include "YarnRpcChannel.h"
#include "YarnRpcRequest.h"
#include "yarn_protocal/yarn_service_protos.pb.h"
#include "yarn_protocal/RpcHeader.pb.h"
#include "yarn_protocal/ProtobufRpcEngine.pb.h"
#include "yarn_protocal/applicationclient_protocol.pb.h"



using namespace hadoop::common;

const Logger YarnRpcChannel::LOG = Logger::getInstance(LOG4CPLUS_TEXT("YarnRpcChannel"));

const int YarnRpcChannel::CLIENT_PROTOCAL_VERSION = 1;

YarnRpcChannel::YarnRpcChannel(void)
{
}


YarnRpcChannel::~YarnRpcChannel(void)
{
}

void YarnRpcChannel::CallMethod(const MethodDescriptor* method, RpcController* controller, 
	const Message* request, Message* response, Closure* done) {
		
		LOG4CPLUS_INFO(YarnRpcChannel::LOG, "CallMethod fullname:" << method->full_name());
		const ServiceDescriptor* service_desc = method->service();
		if (service_desc) {
			LOG4CPLUS_INFO(YarnRpcChannel::LOG, "service info:"<< service_desc->full_name());
		}

		RequestHeaderProto rpc_request_header;
		const char* PROTOCAL_NAME = "org.apache.hadoop.yarn.api.ApplicationClientProtocolPB";
		
		rpc_request_header.set_methodname(method->name());
		rpc_request_header.set_declaringclassprotocolname(service_desc->full_name());
		rpc_request_header.set_clientprotocolversion(YarnRpcChannel::CLIENT_PROTOCAL_VERSION);

		YarnRpcRequest yarn_rpc_request(&rpc_request_header, &request);


		RpcRequestHeaderProto rpc_request_header;
		rpc_request_header.set_rpckind(RPC_PROTOCOL_BUFFER);
		rpc_request_header.set_rpcop(RpcRequestHeaderProto_OperationProto_RPC_FINAL_PACKET);
		rpc_request_header.set_callid(method->index());
		rpc_request_header.set_retrycount(1);

		






}
