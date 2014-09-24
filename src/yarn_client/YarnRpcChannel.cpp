#include "YarnRpcChannel.h"
#include "YarnRpcRequest.h"
#include "yarn_protocal/yarn_service_protos.pb.h"
#include "yarn_protocal/RpcHeader.pb.h"
#include "yarn_protocal/ProtobufRpcEngine.pb.h"
#include "yarn_protocal/applicationclient_protocol.pb.h"



using namespace hadoop::common;

const Logger YarnRpcChannel::LOG = Logger::getInstance(LOG4CPLUS_TEXT("YarnRpcChannel"));

const int YarnRpcChannel::CLIENT_PROTOCAL_VERSION = 1;
const char* YarnRpcChannel::RESOURCEMANAGER_ADDRESS = "yarn.resourcemanager.address";

YarnRpcChannel::YarnRpcChannel(const Configure* conf, char* protocol_name){
	m_conf = conf;
	m_protocol_name = protocol_name;
	init_connection();
}

void YarnRpcChannel::init_connection() {	
	const string* rm_address = m_conf->get_property(RESOURCEMANAGER_ADDRESS);
	if (rm_address) {
		boost::shared_ptr<ConnectionId> conn_id(new ConnectionId());
		conn_id->set_address(*rm_address);
		conn_id->protocal_name = "org.apache.hadoop.yarn.api.ApplicationClientProtocolPB";
		conn_id->user_information = new UserInformationProto();
		conn_id->user_information->set_effectiveuser("Administrator");
		m_yarn_conn.reset(new Connection((ConnectionId*)conn_id.get()));
		m_yarn_conn->build_connection_context();
	}
}


YarnRpcChannel::~YarnRpcChannel(void) {
}

void YarnRpcChannel::set_protocol_name(char* protocol_name) {
	m_protocol_name = protocol_name;
}

void YarnRpcChannel::CallMethod(const MethodDescriptor* method, RpcController* controller, 
	const Message* request, Message* response, Closure* done) {
		
		LOG4CPLUS_INFO(YarnRpcChannel::LOG, "CallMethod fullname:" << method->full_name());
		const ServiceDescriptor* service_desc = method->service();
		if (service_desc) {
			LOG4CPLUS_INFO(YarnRpcChannel::LOG, "service info:"<< service_desc->full_name());
		}

		RequestHeaderProto rpc_request_header;
		rpc_request_header.set_methodname(method->name());
		rpc_request_header.set_declaringclassprotocolname(m_protocol_name);
		rpc_request_header.set_clientprotocolversion(YarnRpcChannel::CLIENT_PROTOCAL_VERSION);

		YarnRpcRequest yarn_rpc_request(&rpc_request_header, request);

		Call new_app_call(Call::get_new_callid(), RPC_PROTOCOL_BUFFER, &yarn_rpc_request);
		m_yarn_conn->send_rpc_request(&new_app_call);

		m_yarn_conn->receive_rpc_response(response);

}
