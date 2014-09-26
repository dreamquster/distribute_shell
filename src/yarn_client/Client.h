#ifndef YARN_RpcSASLClient_H__fdsyisd_1424rY_
#define YARN_RpcSASLClient_H__fdsyisd_1424rY_
#include "common.h"
#include "YarnRpcRequest.h"
#include <sasl/sasl.h>

class RpcSASLClient
{
public:
	static const Logger LOG;
	RpcSASLClient(int& remote_server);
	~RpcSASLClient(void);

	void sasl_connect(void);
private:
	void send_sasl_message(RpcSaslProto& message);

	RpcSaslProto get_init_sasl_response(RpcSaslProto& sasl_message);

	const RpcSaslProto_SaslAuth&  create_sasl_client(RpcSaslProto& sasl_message);

	void init_sasl_client_by_authtype(const RpcSaslProto_SaslAuth& auth_type);

	void select_token(const string& service_name);


		
private:
	int m_sasl_server_fd;
	sasl_conn_t* m_sasl_conn;
};
#endif


