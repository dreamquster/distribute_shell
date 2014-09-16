#include <iostream>
#include "tinyxml2.h"
#include "Configure.h"
using namespace std;

int main(int argc, char* args[]) {
	Configure yarn_conf;
	yarn_conf.loadXML("yarn-conf.xml");
	return 0;
}