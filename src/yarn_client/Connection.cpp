#include "Connection.h"
#include <unistd.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>  
#include <sstream>
#include "utils/const_variable.h"
#include <google/protobuf/service.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

using namespace google::protobuf;
using namespace google::protobuf::io;
using std::ostringstream;
using std::endl;

Logger Connection::LOG = Logger::getInstance(LOG4CPLUS_TEXT("Connection"));

Connection::Connection(const string& host, const int port)
{
	this->m_remote_host = host;
	this->m_remote_port = port;
	this->m_remote_sock = NetUtils::INVALID_SOCKET;
	if (NetUtils::INVALID_SOCKET == (m_remote_sock = socket(AF_INET, SOCK_STREAM, 0))) {
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

	//pthread_create(this->m_call_thread, NULL, Connection::call_handler, (void*)this);

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

void Connection::write( char* message_data, int message_len )
{
	if (m_remote_sock != NetUtils::INVALID_SOCKET) {
		send(m_remote_sock, message_data, message_len, 0);
	}
}


int Connection::receive(char* buf, int buf_len) {
	if (m_remote_sock != NetUtils::INVALID_SOCKET) {
		return recv(m_remote_sock, buf, buf_len, 0);
	}
	return ERR_RETURN;
}

void Connection::send_connection_context(string& protocal,const char* auth_method) {
	string debug_msg;
	IpcConnectionContextProto connect_context_message;
	connect_context_message.set_protocol(protocal.c_str());
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
					
	char arr_buffer[1024];
	ArrayOutputStream arr_ostream(arr_buffer, 1024);
	CodedOutputStream coded_ostream(&arr_ostream);
	char int_buf[4];
	fill_big_endian_int32(total_size, int_buf);
	coded_ostream.WriteRaw(&total_size, sizeof(total_size));
	uint8* request_buffer = coded_ostream.GetDirectBufferForNBytesAndAdvance(
		CodedOutputStream::VarintSize32(header_size) + header_size);
	if (NULL != request_buffer) {
		coded_ostream.WriteVarint32(header_size);
		rpc_request_header.SerializeToCodedStream(&coded_ostream);
	}

	coded_ostream.WriteVarint32(request_size);
	connect_context_message.SerializeToCodedStream(&coded_ostream);
	
	debug_msg = "CodedStream size:" + coded_ostream.ByteCount();
	LOG4CPLUS_DEBUG(Connection::LOG, debug_msg.c_str());

	char* message_data = NULL;
	int message_len = 0;
	coded_ostream.GetDirectBufferPointer((void**)&message_data, &message_len);
	
	debug_msg = string(message_data, message_data + message_len);
	LOG4CPLUS_DEBUG(Connection::LOG, debug_msg.c_str());

	write(message_data, message_len);

	return;
}
void* Connection::call_handler(void* args) {
	Connection* call_connection= static_cast<Connection*>(args);
	if (call_connection) {
		MethodLocker(call_connection->get_obj_mutex());
			
	}
}

int Connection::sendConncetionHeader(void)
{
	const char server_class = 0; //int0对应的char 为48
	const char auth_callid = 0;
	ostringstream osstream;
	osstream<<RpcConstant::HEADER<<RpcConstant::CURRENT_VERSION
		<<server_class<<auth_callid;
	write(osstream.str());
	return 0;
}

int Connection::shutdown() {
	if (NetUtils::INVALID_SOCKET != m_remote_sock) {
		close(m_remote_sock);
	}	
	return 0;
}
