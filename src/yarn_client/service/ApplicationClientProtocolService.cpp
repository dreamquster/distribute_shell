#include  "ApplicationClientProtocolService.h"

const char* ApplicationClientProtocolServiceImpl::PROTOCOL_NAME 
	= "org.apache.hadoop.yarn.api.ApplicationClientProtocolPB";
const Logger ApplicationClientProtocolServiceImpl::LOG = 
	Logger::getInstance(LOG4CPLUS_TEXT("ApplicationClientProtocolServiceImpl"));

ApplicationClientProtocolServiceImpl::ApplicationClientProtocolServiceImpl(const Configure* conf) {
	this->m_conf = conf;
	this->m_rpc_channel = new YarnRpcChannel(conf, (char*)PROTOCOL_NAME);
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

shared_ptr<ApplicationSubmissionContext> ApplicationClientProtocolServiceImpl::create_application() {
	GetNewApplicationRequestProto request;
	GetNewApplicationResponseProto response;
	app_client_service_stub->getNewApplication(NULL, &request, &response, NULL);
	

	shared_ptr<ApplicationSubmissionContext> app_submit_context(new ApplicationSubmissionContext());
	app_submit_context->set_allocated_application_id(new ApplicationIdProto(response.application_id()));

	return app_submit_context;
}

void ApplicationClientProtocolServiceImpl::
	submit_application(shared_ptr<ApplicationSubmissionContext> app_context) {
		SubmitApplicationRequestProto request;
		SubmitApplicationResponseProto response;
		request.set_allocated_application_submission_context(app_context.get());
		app_client_service_stub->submitApplication(NULL, &request, &response, NULL);

		int poll_time = 0;
		while(true) {
			const ApplicationReport& report = get_application_report((ApplicationId*)&app_context->application_id());
			if (report.yarn_application_state() != NEW 
				&& report.yarn_application_state() != NEW_SAVING) {
					break;
			}
			if (0 == (poll_time%10)) {
				LOG4CPLUS_DEBUG(LOG, "Application submission is not finished, " <<
					"submitted application " << app_context->application_id().id() <<
					" is still in " << report.yarn_application_state());
			}
		}
}

const ApplicationReport& ApplicationClientProtocolServiceImpl::
	get_application_report(ApplicationId* app_id) {
		GetApplicationReportRequestProto request;
		GetApplicationReportResponseProto response;
		request.set_allocated_application_id(app_id);
		app_client_service_stub->getApplicationReport(NULL, &request, &response, NULL);

		return response.application_report();
}

