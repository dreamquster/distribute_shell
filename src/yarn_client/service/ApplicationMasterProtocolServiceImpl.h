#ifndef APPLICATIONMASTERPROTOCOLSERVICE_IMPL_H_otewo1954325
#define APPLICATIONMASTERPROTOCOLSERVICE_IMPL_H_otewo1954325


#include <google/protobuf/service.h>
#include "../yarn_protocal/applicationmaster_protocol.pb.h"
#include "../YarnRpcChannel.h"


using namespace hadoop::yarn;

class ApplicationMasterProtocolServiceImpl {
public:
	static const char* PROTOCOL_NAME;
	static const string SERVER_ADDRESS_CONF_PROP;

	static const Logger LOG;

	ApplicationMasterProtocolServiceImpl(const Configure* conf);

	virtual ~ApplicationMasterProtocolServiceImpl();

	bool registerApplicationMaster(const string& app_host_name, const int app_host_port,
		const string* tracking_url = NULL);
private:
	const Configure* m_conf;
	YarnRpcChannel* m_rpc_channel;

	ApplicationMasterProtocolService_Stub* app_master_service_stub;
	
};

#endif