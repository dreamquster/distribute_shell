#ifndef APPLICATIONCLIENTPROTOCOL_SERVICE_H_ytoeurt_5345_
#define APPLICATIONCLIENTPROTOCOL_SERVICE_H_ytoeurt_5345_

#include <google/protobuf/service.h>
#include "../yarn_protocal/applicationclient_protocol.pb.h"
#include "../YarnRpcChannel.h"

using namespace hadoop::yarn;


typedef ApplicationSubmissionContextProto ApplicationSubmissionContext;
typedef ::hadoop::yarn::ContainerLaunchContextProto ContainerLaunchContext;
typedef ApplicationIdProto ApplicationId;
typedef ApplicationReportProto ApplicationReport;


class YarnClientApplication{

};

class ApplicationClientProtocolServiceImpl {
public:
	static const char* PROTOCOL_NAME;
	static const string SERVER_ADDRESS_CONF_PROP;
	static const Logger LOG;

	ApplicationClientProtocolServiceImpl(const Configure* conf);

	virtual ~ApplicationClientProtocolServiceImpl();

	bool create_application(ApplicationSubmissionContext& app_submit_context); 

	void submit_application(const ApplicationSubmissionContext& app_context);

	const ApplicationReport get_application_report(const ApplicationId& app_id);



private:
	const Configure* m_conf;
	ApplicationClientProtocolService_Stub* app_client_service_stub;
	YarnRpcChannel* m_rpc_channel;
};

#endif