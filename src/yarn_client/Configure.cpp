#include "Configure.h"
#include "tinyxml2.h"
#include <iostream>
using namespace tinyxml2;
using namespace std;

const char* Configure::HADOOP_PROP = "property";

Configure::Configure(void)
{
}


Configure::~Configure(void)
{
}


int Configure::loadXML(string conf_file)
{
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
