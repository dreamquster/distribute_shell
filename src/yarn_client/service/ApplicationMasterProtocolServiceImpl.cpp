#include "ApplicationMasterProtocolServiceImpl.h"

using namespace ::hadoop::yarn;
const char* ApplicationMasterProtocolServiceImpl::PROTOCOL_NAME 
	= "org.apache.hadoop.yarn.api.ApplicationMasterProtocolPB";
const string ApplicationMasterProtocolServiceImpl::SERVER_ADDRESS_CONF_PROP 
	= "yarn.resourcemanager.scheduler.address";

const Logger ApplicationMasterProtocolServiceImpl::LOG = 
	Logger::getInstance(LOG4CPLUS_TEXT("ApplicationMasterProtocolServiceImpl"));

static string AUTH_TOKEN = "TOKEN";
ApplicationMasterProtocolServiceImpl::ApplicationMasterProtocolServiceImpl(const Configure* conf) {
	this->m_conf = conf;
	this->m_rpc_channel = new YarnRpcChannel(conf, (char*)PROTOCOL_NAME, 
		*conf->get_property(SERVER_ADDRESS_CONF_PROP));
	
	m_rpc_channel->set_auth_method(AUTH_TOKEN);
	m_rpc_channel->init_connection();
	this->app_master_service_stub = new ApplicationMasterProtocolService_Stub(m_rpc_channel);
}

ApplicationMasterProtocolServiceImpl::~ApplicationMasterProtocolServiceImpl() {
	if (app_master_service_stub) {
		delete app_master_service_stub;
	}

	if (m_rpc_channel) {
		delete m_rpc_channel;
	}
}


bool ApplicationMasterProtocolServiceImpl::registerApplicationMaster(const string& app_host_name, 
	const int app_host_port, const string* tracking_url/* =NULL*/) {
		RegisterApplicationMasterRequestProto request;
		RegisterApplicationMasterResponseProto response;
		request.set_host(app_host_name);
		request.set_rpc_port(app_host_port);
		if (tracking_url) {
			request.set_tracking_url(*tracking_url);
		}
		
		LOG4CPLUS_DEBUG(LOG, "registerApplicationMaster with app_host_name:"<<app_host_name
		<<" app_host_port:"<<app_host_port);

		app_master_service_stub->registerApplicationMaster(NULL, &request, &response, NULL);


}