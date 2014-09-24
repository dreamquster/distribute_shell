#ifndef APPLICATIONCLIENTPROTOCOL_SERVICE_H_ytoeurt_5345_
#define APPLICATIONCLIENTPROTOCOL_SERVICE_H_ytoeurt_5345_

#include <google/protobuf/service.h>
#include "../yarn_protocal/applicationclient_protocol.pb.h"
#include "../YarnRpcChannel.h"

using namespace hadoop::yarn;
using boost::shared_ptr;

typedef ApplicationSubmissionContextProto ApplicationSubmissionContext;
typedef ::hadoop::yarn::ContainerLaunchContextProto ContainerLaunchContext;
typedef ApplicationIdProto ApplicationId;
typedef ApplicationReportProto ApplicationReport;


class YarnClientApplication{

};

class ApplicationClientProtocolServiceImpl {
public:
	static const char* PROTOCOL_NAME;
	static const Logger LOG;

	ApplicationClientProtocolServiceImpl(const Configure* conf);

	virtual ~ApplicationClientProtocolServiceImpl();

	shared_ptr<ApplicationSubmissionContext> create_application(void); 

	void submit_application(shared_ptr<ApplicationSubmissionContext> app_context);

	const ApplicationReport& get_application_report(ApplicationId* app_id);

private:
	const Configure* m_conf;
	ApplicationClientProtocolService_Stub* app_client_service_stub;
	YarnRpcChannel* m_rpc_channel;
};

#endif