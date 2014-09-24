#ifndef CONFIGURE_4235423_fjehgeti5_H__
#define CONFIGURE_4235423_fjehgeti5_H__
#include "common.h"
#include <string>
#include <map>
using std::string;
using std::map;

class Configure
{
public:
	static const Logger LOG;


	Configure(void);
	~Configure(void);
	int loadXML(string conf_file);

	const string* get_property(const string& key) const;

	bool get_int_prop(const string& key, int* res) const;

private:
	const static char* HADOOP_PROP;
	map<string, string> m_conf_properties;
};
#endif


