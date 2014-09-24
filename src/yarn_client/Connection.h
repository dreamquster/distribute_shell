#ifndef CONNECTION_H__4343hljfasldfjdsl_fdasfhewo
#define CONNECTION_H__4343hljfasldfjdsl_fdasfhewo
#include <string>
#include <iostream>
#include <map>
#include "pthread.h"
#include "common.h"
#include "utils/ResourceLock.h"
#include "yarn_protocal/RpcHeader.pb.h"
#include "yarn_protocal/ipcConnectionContext.pb.h"

#include "YarnRpcRequest.h"


using namespace hadoop::common;
using std::string;
using std::cerr;
using std::endl;
using std::map;
using ::google::protobuf::Message;
using log4cplus::Logger;

class Call :virtual public ResourceLock{
public:
	static boost::atomic<int> next_callid;

	static int get_new_callid(void) {
		int val = next_callid.load();
		next_callid.store(val + 1);
		return val;
	}


	Call(int id, RpcKindProto rpc_kind, RpcCodedMessage* request_param) {
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

	RpcCodedMessage* Request_msg() const { return m_request_msg; }


private:
	

	int m_id;
	RpcKindProto m_rpc_kind;
	bool m_done;
	RpcCodedMessage* m_request_msg;
	
	Message* m_response_msg;	

};

struct ConnectionId {
	string remote_host;
	int	remote_port;
	string protocal_name;
	UserInformationProto* user_information;

	void set_address(const string& address);

};



class Connection : virtual public ResourceLock
{
public:
	static Logger LOG;

	

	Connection(ConnectionId* conn_id);
	~Connection(void);
	int write(const string& msg);

	int receive(char* buf, int buf_len);

	static void* call_handler(void* p_conn);

	void build_connection_context(void);

	void send_rpc_request(Call* rpc_call);

	void receive_rpc_response(Message* const response);

	int shutdown(void);
private:
	void connect_to(const string& host, const int port) ;
	void send_connection_context(string& protocal, const char* auth_method);
	int send_conncetion_header(void);

	void write(const char* message_data, int message_len);


private:
	static const int CONNECTION_CONTEXT_CALL_ID = -3;
	static const int RPC_CALL_ID = 0;
private:
	boost::shared_ptr<ConnectionId> m_connection_info;
	int state;
	int m_remote_sock;
	map<int, Call> m_send_calls;
	;
	pthread_t* m_call_thread;
	string client_id;

	
};


#endif


