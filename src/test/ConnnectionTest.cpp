#include <gtest/gtest.h>
#include "common.h"
#include "pthread.h"
#include <google/protobuf/service.h>

#define private public

#include "Connection.h"
#include "YarnRpcRequest.h"
#include "yarn_protocal/yarn_service_protos.pb.h"
#include "yarn_protocal/ProtobufRpcEngine.pb.h"

using namespace google::protobuf;
using namespace hadoop::yarn;


using namespace std;

class ConnectionTest: public testing::Test {
public:	
	static Logger LOG;
protected:
	//Override
	virtual void SetUp() {
		m_yarn_conn = new Connection("127.0.0.1", 24322);
	}

	virtual void TearDown() {
		m_yarn_conn->shutdown();
	}
protected:
	Connection* m_yarn_conn;
};


Logger ConnectionTest::LOG = Logger::getInstance(LOG4CPLUS_TEXT("ConnectionTest"));

TEST_F(ConnectionTest, TestOneRPC) {
	m_yarn_conn->send_conncetion_header();
	m_yarn_conn->m_user_information = new UserInformationProto();
	m_yarn_conn->m_user_information->set_effectiveuser("Administrator");
	string protocal_name = "org.apache.hadoop.yarn.api.ApplicationClientProtocolPB";
	m_yarn_conn->send_connection_context(protocal_name,
		NULL);

	RequestHeaderProto request_header;
	request_header.set_methodname("getNewApplication");
	request_header.set_declaringclassprotocolname("org.apache.hadoop.yarn.api.ApplicationClientProtocolPB");
	google::protobuf::uint64 protocal_version = 1L;
	request_header.set_clientprotocolversion(protocal_version);
	GetNewApplicationRequestProto get_new_app_request;

	YarnRpcRequest yarn_rpc_request(&request_header, &get_new_app_request);
	
	
	Call new_app_call(0, RPC_PROTOCOL_BUFFER, &yarn_rpc_request);
	m_yarn_conn->send_rpc_request(&new_app_call);

	GetNewApplicationResponseProto response;
	m_yarn_conn->receive_rpc_response(&response);
	LOG4CPLUS_INFO(Connection::LOG, "receive rpc response content:" );
}