#ifndef YARN_RPC_CHANNEL_5fprotocol_2eproto__H
#define YARN_RPC_CHANNEL_5fprotocol_2eproto__H
#include <google/protobuf/service.h>

#include "common.h"

using namespace ::google::protobuf;

class YarnRpcChannel:public ::google::protobuf::RpcChannel {
public:
	static const Logger LOG;
	YarnRpcChannel(void);
	~YarnRpcChannel(void);


public:
	void CallMethod(const MethodDescriptor* method,
		RpcController* controller,
		const Message* request,
		Message* response,
		Closure* done);
private:
	static const int CLIENT_PROTOCAL_VERSION;
};
#endif

