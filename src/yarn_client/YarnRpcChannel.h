#ifndef YARN_RPC_CHANNEL_5fprotocol_2eproto__H
#define YARN_RPC_CHANNEL_5fprotocol_2eproto__H
#include <google/protobuf/service.h>
using namespace ::google::protobuf;

class YarnRpcChannel:public ::google::protobuf::RpcChannel
{
public:
	YarnRpcChannel(void);
	~YarnRpcChannel(void);


public:
	void CallMethod(const MethodDescriptor* method,
		RpcController* controller,
		const Message* request,
		Message* response,
		Closure* done);
};
#endif

