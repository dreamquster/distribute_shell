#ifndef BLOCKINGQUEUE_TEST_H_eyoew_532q_te
#define BLOCKINGQUEUE_TEST_H_eyoew_532q_te
#include <gtest/gtest.h>
#include "pthread.h"

#define private public

#include "service/ApplicationClientProtocolService.h"
using namespace std;


class AppClientProtocolServiceTest: public testing::Test {
public:	
	static Logger LOG;
protected:
	//Override
	virtual void SetUp() {
		Configure conf;
		conf.loadXML("D:\\EveryDayDoc\\2014-9-1\\yarn-learn-git\\target\\test-classes\\yarn-conf.xml");
		app_client_protocol_impl = new ApplicationClientProtocolServiceImpl(&conf);
	}

	virtual void TearDown() {
		delete app_client_protocol_impl;
	}
protected:
	ApplicationClientProtocolServiceImpl* app_client_protocol_impl;

};

Logger AppClientProtocolServiceTest::LOG = Logger::getInstance(LOG4CPLUS_TEXT("AppClientProtocolServiceTest"));

TEST_F(AppClientProtocolServiceTest, CreateApplication) {
	shared_ptr<ApplicationSubmissionContext> app_submit_context = app_client_protocol_impl->create_application();
	app_submit_context->set_application_name("fanming test");
	shared_ptr<ContainerLaunchContext> am_container(new ContainerLaunchContext());

	app_submit_context->set_allocated_am_container_spec(am_container.get());
	app_submit_context->set_unmanaged_am(true);
	app_client_protocol_impl->submit_application(app_submit_context);
}

#endif