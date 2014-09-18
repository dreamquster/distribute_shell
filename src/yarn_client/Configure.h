#ifndef CONFIGURE_4235423_fjehgeti5_H__
#define CONFIGURE_4235423_fjehgeti5_H__
#include <string>
#include <map>
using std::string;
using std::map;

class Configure
{
public:
	Configure(void);
	~Configure(void);
	int loadXML(string conf_file);
private:
	const static char* HADOOP_PROP;
	map<string, string> m_conf_properties;
};
#endif


