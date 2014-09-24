#include "Configure.h"
#include "tinyxml2.h"
#include <iostream>

using namespace tinyxml2;
using namespace std;

const char* Configure::HADOOP_PROP = "property";
const Logger Configure::LOG = Logger::getInstance(LOG4CPLUS_TEXT("Configure"));

Configure::Configure(void) {
}


Configure::~Configure(void) {
}


int Configure::loadXML(string conf_file) {
	 XMLDocument conf_xml_doc;
	 if (XML_SUCCESS != conf_xml_doc.LoadFile(conf_file.c_str())) {
		 return -1;
	 }

	 
	 XMLElement* root_configuration_ptr = conf_xml_doc.RootElement();
	 if (root_configuration_ptr) {
		 XMLElement* property_ptr = root_configuration_ptr->FirstChildElement(Configure::HADOOP_PROP);
		 while(property_ptr) {
			 XMLElement* name_ptr = property_ptr->FirstChildElement("name");
			 XMLElement* value_ptr = property_ptr->FirstChildElement("value");
			 if (name_ptr && value_ptr && name_ptr->GetText()) {
				 if (value_ptr->GetText()) {
					m_conf_properties[name_ptr->GetText()] = value_ptr->GetText();
				 } else {
					m_conf_properties[name_ptr->GetText()] = "";
				 }
			 }
			property_ptr = property_ptr->NextSiblingElement(Configure::HADOOP_PROP); 
		 }
	 }
	 
	return 0;
}

const string* Configure::get_property(const string& key) const{
	map<string, string>::const_iterator it = m_conf_properties.find(key);
	if (it != m_conf_properties.end()) {
		return &(it->second);
	} else {
		LOG4CPLUS_DEBUG(Configure::LOG, "the property of "<< key << "do not exist");
		return NULL;
	}	
}

bool Configure::get_int_prop(const string& key, int* res) const {
	const string* str_val = get_property(key);
	if (str_val) {
		return ConvertUtils::to_int(*str_val, res);
	}
	return false;		
}