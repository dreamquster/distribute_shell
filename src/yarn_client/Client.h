#ifndef YARN_RpcSASLClient_H__fdsyisd_1424rY_
#define YARN_RpcSASLClient_H__fdsyisd_1424rY_
#include "common.h"
#include "YarnRpcRequest.h"

class RpcSASLClient
{
public:
	static const Logger LOG;
	RpcSASLClient(int& remote_server);
	~RpcSASLClient(void);

	void sasl_connect(void);
private:
	private void send_sasl_message(RpcSaslProto& message);
		
private:
	int m_sasl_server_fd;
};
#endif


