#ifndef APPLICATIONCLIENTPROTOCOL_SERVICE_H_ytoeurt_5345_
#define APPLICATIONCLIENTPROTOCOL_SERVICE_H_ytoeurt_5345_

#include <google/protobuf/service.h>
#include "yarn_protocal/applicationclient_protocol.pb.h"

using namespace hadoop::yarn;

class YarnClientApplication{

};

class ApplicationClientProtocolServiceImpl {
public:
	ApplicationClientProtocolServiceImpl(::google::protobuf::RpcChannel* channel);

	virtual ~ApplicationClientProtocolServiceImpl();

	YarnClientApplication create_application(void); 

private:
	ApplicationClientProtocolService_Stub* app_client_service_stub;
};

#endif