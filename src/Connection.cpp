#include "Connection.h"
#include <unistd.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sstream>
#include "utils/const_variable.h"
#include <google/protobuf/io/coded_stream.h>

using namespace google::protobuf::io;
using std::ostringstream;
using std::endl;



Connection::Connection(const string& host, const int port)
{
	this->m_remote_host = host;
	this->m_remote_port = port;
	this->m_remote_sock = NetUtils::INVALID_SOCKET;
	if (-1 != (m_remote_sock = socket(AF_INET, SOCK_STREAM, 0))) {
		return;
	}
	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	if(inet_pton(AF_INET, m_remote_host.c_str(), &server_addr.sin_addr.s_addr) <= 0) {
		return;
	}
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(m_remote_port);
	if (connect(m_remote_sock, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		return;
	}

	pthread_create(this->m_call_thread, NULL, Connection::call_handler, (void*)this);

}


Connection::~Connection(void)
{
}


int Connection::write(const string& msg) const
{ 
	if (m_remote_sock != NetUtils::INVALID_SOCKET) {
		return send(m_remote_sock, msg.c_str(), msg.length(), 0);
	}
	return ERR_RETURN;
}

int Connection::receive(char* buf, int buf_len) {
	if (m_remote_sock != NetUtils::INVALID_SOCKET) {
		return recv(m_remote_sock, buf, buf_len, 0);
	}
	return ERR_RETURN;
}

void Connection::send_connection_context(string& protocal, string& auth_method) {
	IpcConnectionContextProto connect_context_message;
	connect_context_message.set_protocol(protocal.c_str());
	connect_context_message.set_allocated_protocol(&auth_method);
	connect_context_message.set_allocated_userinfo(this->m_user_information);

	RpcRequestHeaderProto rpc_request_header;
	rpc_request_header.set_rpckind(RPC_PROTOCOL_BUFFER);
	rpc_request_header.set_rpcop(RpcRequestHeaderProto::RPC_CONTINUATION_PACKET);
	rpc_request_header.set_callid(CONNECTION_CONTEXT_CALL_ID);
	rpc_request_header.set_retrycount(RpcConstant::INVALID_TRIES);
	rpc_request_header.set_clientid(client_id.c_str());

	int header_size = rpc_request_header.ByteSize();
	int request_size = connect_context_message.ByteSize();
	int total_size = CodedOutputStream::VarintSize32(header_size) + header_size 
		+ CodedOutputStream::VarintSize32(request_size) + request_size; 
					
	ostringstream osstream;
	osstream<<total_size
			<<header_size;
	rpc_request_header.SerializePartialToOstream(&osstream);
	osstream<<request_size;
	connect_context_message.SerializePartialToOstream(&osstream);

	write(osstream.str());
}
void* Connection::call_handler(void* args) {
	Connection* call_connection= static_cast<Connection*>(args);
	if (call_connection) {
		MethodLocker(call_connection->get_obj_mutex());
			
	}
}

int Connection::sendConncetionHeader(void)
{
	const int server_class = 0;
	const int auth_callid = 0;
	ostringstream osstream;
	osstream<<RpcConstant::HEADER<<RpcConstant::CURRENT_VERSION
		<<server_class<<auth_callid;
	write(osstream.str());
	return 0;
}
