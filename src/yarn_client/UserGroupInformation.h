#ifndef USER_GROUP_INFORMATION_H_432432_jtteojh0_
#define USER_GROUP_INFORMATION_H_432432_jtteojh0_

#include <map>
#include <string>
using std::map;
using std::string;

class Token {
public:
	string user_name;
	string user_passwd;
};

class UserGroupInformation {
public:

	static void add_service_token(string name, Token& token);
	static const Token* get_service_token(const string& name);
private:
	static map<string, Token> m_sasl_tokens;
};

#endif