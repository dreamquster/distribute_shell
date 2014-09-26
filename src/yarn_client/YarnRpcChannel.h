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

	YarnRpcChannel(const Configure* conf, const string& protocol_name,
		const string& server_addr);
	~YarnRpcChannel(void);

	void set_auth_method(string& authmethod);

	void init_connection(void); 

public:
	void CallMethod(const MethodDescriptor* method,
		RpcController* controller,
		const Message* request,
		Message* response,
		Closure* done);
private:
	
private:
	static const int CLIENT_PROTOCAL_VERSION;
	const Configure* m_conf;
	string m_protocol_name;
	string m_server_address;
	boost::scoped_ptr<Connection> m_yarn_conn;

	string m_auth_method;
};
#endif

