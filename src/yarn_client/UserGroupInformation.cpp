#include "UserGroupInformation.h"

map<string, Token> UserGroupInformation::m_sasl_tokens;

const Token* UserGroupInformation::get_service_token(const string& name) {
	map<string, Token>::const_iterator cit = m_sasl_tokens.find(name);
	if (cit != m_sasl_tokens.end()) {
		return &(cit->second);
	} else {
		return NULL;
	}
}

void UserGroupInformation::add_service_token(string name, Token& token) {
	m_sasl_tokens[name] = token;
}