#include  "ApplicationClientProtocolService.h"

const char* ApplicationClientProtocolServiceImpl::PROTOCOL_NAME 
	= "org.apache.hadoop.yarn.api.ApplicationClientProtocolPB";
const string ApplicationClientProtocolServiceImpl::SERVER_ADDRESS_CONF_PROP 
	= "yarn.resourcemanager.address";

const Logger ApplicationClientProtocolServiceImpl::LOG = 
	Logger::getInstance(LOG4CPLUS_TEXT("ApplicationClientProtocolServiceImpl"));


ApplicationClientProtocolServiceImpl::ApplicationClientProtocolServiceImpl(const Configure* conf) {
	this->m_conf = conf;
	this->m_rpc_channel = new YarnRpcChannel(conf, (char*)PROTOCOL_NAME, 
		*conf->get_property(SERVER_ADDRESS_CONF_PROP));
	this->app_client_service_stub = new ApplicationClientProtocolService_Stub(m_rpc_channel);
}

ApplicationClientProtocolServiceImpl::~ApplicationClientProtocolServiceImpl() {
	if (app_client_service_stub) {
		delete app_client_service_stub;
	}

	if (m_rpc_channel) {
		delete m_rpc_channel;
	}
}

bool ApplicationClientProtocolServiceImpl::create_application(
	ApplicationSubmissionContext& app_submit_context) {
	GetNewApplicationRequestProto request;
	GetNewApplicationResponseProto response;
	app_client_service_stub->getNewApplication(NULL, &request, &response, NULL);
	
	
	app_submit_context.set_allocated_application_id(new ApplicationIdProto(response.application_id()));	
	
		
	return true;
}

void ApplicationClientProtocolServiceImpl::
	submit_application(const ApplicationSubmissionContext& app_context) {
		SubmitApplicationRequestProto request;
		SubmitApplicationResponseProto response;
		ApplicationSubmissionContext* app_context_copy = new ApplicationSubmissionContext(app_context);
		request.set_allocated_application_submission_context(app_context_copy);
		app_client_service_stub->submitApplication(NULL, &request, &response, NULL);

		int poll_time = 0;
		while(true) {
			const ApplicationReport report = get_application_report(app_context.application_id());
			if (report.yarn_application_state() != NEW 
				&& report.yarn_application_state() != NEW_SAVING) {
					break;
			}
			if (0 == (poll_time%10)) {
				LOG4CPLUS_DEBUG(LOG, "Application submission is not finished, " <<
					"submitted application " << app_context.application_id().id() <<
					" is still in " << report.yarn_application_state());
			}
			++poll_time;
		}
}

const ApplicationReport ApplicationClientProtocolServiceImpl::
	get_application_report(const ApplicationId& app_id) {
		GetApplicationReportRequestProto request;
		GetApplicationReportResponseProto response;

		ApplicationId* app_id_copy = new ApplicationId(app_id);
		request.set_allocated_application_id(app_id_copy);
		app_client_service_stub->getApplicationReport(NULL, &request, &response, NULL);

		return response.application_report();
}

