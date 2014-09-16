#ifndef CONNECTION_H__4343hljfasldfjdsl_fdasfhewo
#define CONNECTION_H__4343hljfasldfjdsl_fdasfhewo
#include <string>
#include <iostream>
#include <map>
#include "pthread.h"
#include "utils/ResourceLock.h"
#include "yarn_protocal/RpcHeader.pb.h"
#include "yarn_protocal/ipcConnectionContext.pb.h"
#include "yarn_protocal/RpcHeader.pb.h"

using namespace hadoop::common;
using std::string;
using std::cerr;
using std::endl;
using std::map;

class Call :virtual public ResourceLock{
public:
	Call(int id, RpcKindProto rpc_kind, ::google::protobuf::Message* request_param) {
		this->m_rpc_kind = rpc_kind;
		this->m_id = id;
		this->m_request_msg = request_param;
	}

	virtual ~Call() {
		if (!m_done) {
			cerr<<"call with params:"<< this->m_request_msg << " failed"<<endl;
		}
	}

	const RpcKindProto Rpc_kind() const { return m_rpc_kind; }
	void Rpc_kind(const RpcKindProto val) { m_rpc_kind = val; }
	bool Done() const { return m_done; }
	void Done(bool val) { m_done = val; }
	int Id() const { return m_id; }
	void Id(int val) { m_id = val; }

	

private:
	

	int m_id;
	RpcKindProto m_rpc_kind;
	bool m_done;
	::google::protobuf::Message* m_request_msg;
	::google::protobuf::Message* m_response_msg;

	


};

class Connection : virtual public ResourceLock
{
public:
	Connection(const string& host, const int port);
	~Connection(void);
	int write(const string& msg) const;

	int receive(char* buf, int buf_len);

	static void* call_handler(void* p_conn);
private:
	void send_connection_context(string& protocal, string& auth_method);
private:
	static const int CONNECTION_CONTEXT_CALL_ID = -3;

	string m_remote_host;
	int	m_remote_port;
	int state;
	int m_remote_sock;
	map<int, Call> m_send_calls;
	UserInformationProto* m_user_information;
	pthread_t* m_call_thread;
	string client_id;

public:
	
	int sendConncetionHeader(void);
};
#endif


