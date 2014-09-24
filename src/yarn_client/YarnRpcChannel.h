#ifndef YARN_RPC_CHANNEL_5fprotocol_2eproto__H
#define YARN_RPC_CHANNEL_5fprotocol_2eproto__H
#include <google/protobuf/service.h>

#include "common.h"
#include "Connection.h"

using namespace ::google::protobuf;

class YarnRpcChannel:public ::google::protobuf::RpcChannel {
public:
	static const Logger LOG;
	static const char* RESOURCEMANAGER_ADDRESS;

	YarnRpcChannel(const Configure* conf, char* protocol_name);
	~YarnRpcChannel(void);

	void set_protocol_name(char* protocol_name);
public:
	void CallMethod(const MethodDescriptor* method,
		RpcController* controller,
		const Message* request,
		Message* response,
		Closure* done);
private:
	void init_connection(void); 
private:
	static const int CLIENT_PROTOCAL_VERSION;
	const Configure* m_conf;
	char* m_protocol_name;
	boost::scoped_ptr<Connection> m_yarn_conn;
};
#endif

