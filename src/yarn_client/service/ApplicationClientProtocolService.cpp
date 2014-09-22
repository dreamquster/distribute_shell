#include  "ApplicationClientProtocolService.h"



ApplicationClientProtocolServiceImpl::ApplicationClientProtocolServiceImpl(::google::protobuf::RpcChannel* channel) {
	this->app_client_service_stub = new ApplicationClientProtocolService_Stub(channel);
}

ApplicationClientProtocolServiceImpl::~ApplicationClientProtocolServiceImpl() {
	if (app_client_service_stub) {
		delete app_client_service_stub;
	}
}

YarnClientApplication ApplicationClientProtocolServiceImpl::create_application() {
	GetNewApplicationRequestProto request;
	GetNewApplicationResponseProto response;
	app_client_service_stub->getNewApplication(NULL, &request, &response, NULL);

}