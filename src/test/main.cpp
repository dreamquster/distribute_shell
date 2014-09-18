#include <iostream>
#include <gtest/gtest.h>
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/stringhelper.h>

using namespace std;
using namespace log4cplus;


int main(int argc, char* argv[]) {
	Logger root = Logger::getRoot();
	PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("log_config.properties"));
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

