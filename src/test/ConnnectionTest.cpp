#include <gtest/gtest.h>
#include "pthread.h"

#define private public

#include "Connection.h"
using namespace std;


class ConnectionTest: public testing::Test {
public:	

protected:
	//Override
	virtual void SetUp() {
		m_yarn_conn = new Connection("10.2.23.27", 31179);
	}

	virtual void TearDown() {
		m_yarn_conn->shutdown();
	}
protected:
	Connection* m_yarn_conn;
};

TEST_F(ConnectionTest, TestOneRPC) {
	m_yarn_conn->sendConncetionHeader();
	m_yarn_conn->m_user_information = new UserInformationProto();
	m_yarn_conn->m_user_information->set_effectiveuser("Administrator");
	string protocal_name = "org.apache.hadoop.yarn.api.ApplicationClientProtocolPB";
	m_yarn_conn->send_connection_context(protocal_name,
		NULL);
}