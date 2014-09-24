#ifndef CONVERT_UTILS_H_tetaeo_5432
#define CONVERT_UTILS_H_tetaeo_5432

#include <boost/lexical_cast.hpp>
#include <string>
using std::string;

namespace ConvertUtils {
	static Logger LOG = Logger::getInstance("Namespace-ConvertUtils");

	static bool to_int(const string& str_val, int* res) {
		try{
			*res = boost::lexical_cast<int>(str_val);
			return true;
		} catch (boost::bad_lexical_cast& e) {
			LOG4CPLUS_ERROR(ConvertUtils::LOG, "the wrong format of  "<< str_val <<", it can not convert to int"
				<<" with exception:"<<e.what());
			return false;
		} 	
	}

};

#endif