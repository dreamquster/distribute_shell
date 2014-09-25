#ifndef COMMON_H_ygoaewra_24523_
#define COMMON_H_ygoaewra_24523_
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>  

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/helpers/stringhelper.h>
using log4cplus::Logger;

#include <boost/smart_ptr.hpp>
#include <boost/atomic.hpp>

#include "Configure.h"

#include "utils/ConvertUtils.h"


#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <string>
using std::string;

#endif