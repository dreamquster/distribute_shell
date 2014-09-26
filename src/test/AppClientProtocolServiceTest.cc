#ifndef BLOCKINGQUEUE_TEST_H_eyoew_532q_te
#define BLOCKINGQUEUE_TEST_H_eyoew_532q_te
#include <gtest/gtest.h>
#include "pthread.h"

#define private public

#include "service/ApplicationClientProtocolService.h"
#include "service/ApplicationMasterProtocolServiceImpl.h"
#include "UserGroupInformation.h"
using namespace std;


class AppClientProtocolServiceTest: public testing::Test {
public:	
	static Logger LOG;
protected:
	//Override
	virtual void SetUp() {
		m_conf = new Configure();
		m_conf->loadXML("D:\\EveryDayDoc\\2014-9-1\\yarn-learn-git\\target\\test-classes\\yarn-conf.xml");
		app_client_protocol_impl = new ApplicationClientProtocolServiceImpl(m_conf);
		
	}

	virtual void TearDown() {
		delete app_client_protocol_impl;
	}
protected:
	Configure* m_conf;
	ApplicationClientProtocolServiceImpl* app_client_protocol_impl;
	ApplicationMasterProtocolServiceImpl* app_master_protocol_impl;

};

Logger AppClientProtocolServiceTest::LOG = Logger::getInstance(LOG4CPLUS_TEXT("AppClientProtocolServiceTest"));

TEST_F(AppClientProtocolServiceTest, CreateApplication) {
    ApplicationSubmissionContext app_submit_context;
	app_client_protocol_impl->create_application(app_submit_context);
	app_submit_context.set_application_name("fanming test");
	ContainerLaunchContext* am_container = new ContainerLaunchContext();

	app_submit_context.set_allocated_am_container_spec(am_container);
	app_submit_context.set_unmanaged_am(true);
	app_client_protocol_impl->submit_application(app_submit_context);

	const ApplicationReport report = app_client_protocol_impl->get_application_report(app_submit_context.application_id());
	::hadoop::common::TokenProto token = report.client_to_am_token();
	const string& identifier = token.identifier();
	const string& passwd = token.password();
	Token user_token;
	user_token.user_name = identifier;
	user_token.user_passwd = passwd;
	UserGroupInformation::add_service_token((string)token.service(), user_token);

	app_master_protocol_impl = new ApplicationMasterProtocolServiceImpl(m_conf);
	app_master_protocol_impl->registerApplicationMaster("localhost", -1);
}

#endif