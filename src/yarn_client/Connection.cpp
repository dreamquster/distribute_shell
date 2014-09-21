#include "Connection.h"
#include <unistd.h>
#include <sstream>
#include <iomanip>
#include <boost/smart_ptr/scoped_array.hpp>
#include "utils/const_variable.h"
#include "utils/ByteUtils.h"
#include <google/protobuf/service.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include "YarnRpcRequest.h"
#include "yarn_protocal/yarn_service_protos.pb.h"
#include "yarn_protocal/ProtobufRpcEngine.pb.h"

using namespace google::protobuf;
using namespace google::protobuf::io;
using namespace hadoop::yarn;
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


int Connection::write(const string& msg)
{ 
	if (m_remote_sock != NetUtils::INVALID_SOCKET) {
		int len = msg.length();
		write((const char*)msg.c_str(), len);
		return 0;
	}
	return ERR_RETURN;
}

void Connection::write(const char* message_data, int message_len )
{
	if (m_remote_sock != NetUtils::INVALID_SOCKET) {
		int total_send_bytes = 0;
		while(total_send_bytes < message_len) {
			int send_bytes = send(m_remote_sock, message_data + total_send_bytes, 
				message_len - total_send_bytes, 0);
			if (ERR_RETURN == send_bytes) {
				if (total_send_bytes < message_len) {
					LOG4CPLUS_ERROR(Connection::LOG, "has a remaining "
						<< (message_len - total_send_bytes) << " bytes");
				}
				return;
			}
			total_send_bytes += send_bytes;
		}
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
	rpc_request_header.set_rpcop(RpcRequestHeaderProto::RPC_FINAL_PACKET);
	rpc_request_header.set_callid(CONNECTION_CONTEXT_CALL_ID);
	rpc_request_header.set_retrycount(RpcConstant::INVALID_TRIES);
	rpc_request_header.set_clientid(client_id.c_str());

	YarnRpcRequest yarn_rpc_req(&rpc_request_header, &connect_context_message);

	int len = yarn_rpc_req.get_length();
	if (0 < len) {
		write(yarn_rpc_req.c_str(), len);
	}

	return;
}

void Connection::send_rpc_request(Call* rpc_call){
	RpcRequestHeaderProto rpc_request_header;
	rpc_request_header.set_rpckind(rpc_call->Rpc_kind());
	rpc_request_header.set_rpcop(RpcRequestHeaderProto::RPC_FINAL_PACKET);
	rpc_request_header.set_callid(RPC_CALL_ID);
	rpc_request_header.set_retrycount(RpcConstant::INVALID_TRIES);
	rpc_request_header.set_clientid(client_id.c_str());
	
	RpcMessageWrapper rpc_request_wrapper(&rpc_request_header, rpc_call->Request_msg());

	int len = rpc_request_wrapper.get_length();
	if (0 < len) {
		write(rpc_request_wrapper.c_str(), len);
	}
}

void Connection::receive_rpc_response(Message* response) {
	int response_len = 0;
	receive((char*)&response_len, sizeof(response_len));
	response_len = ntohl(response_len);
	if (0 < response_len) {
		boost::scoped_array<char> buffer(new char[response_len]);
		int buf_pos = 0;
		receive(buffer.get(), response_len);

		uint32 header_len = 0; 
		ByteUtils::ReadVarint32FromArray((uint8*)buffer.get(), &header_len);
		buf_pos += CodedOutputStream::VarintSize32(header_len);
		if (0 < header_len) {
			RpcResponseHeaderProto header;
			header.ParseFromArray((void*)(buffer.get() + buf_pos), header_len);
			buf_pos += header_len;

			RpcResponseHeaderProto::RpcStatusProto status = header.status();
			if (status == RpcResponseHeaderProto::SUCCESS) {
				LOG4CPLUS_INFO(Connection::LOG, "call successed");

				uint32 body_len = 0;
				ByteUtils::ReadVarint32FromArray((uint8*)(buffer.get() + buf_pos), &body_len);
				buf_pos += CodedOutputStream::VarintSize32(body_len);
				response->ParseFromArray((void*)(buffer.get() + buf_pos), body_len);
			}
			

		}
	}
}

void* Connection::call_handler(void* args) {
	Connection* call_connection= static_cast<Connection*>(args);
	if (call_connection) {
		MethodLocker(call_connection->get_obj_mutex());
			
	}
}

int Connection::send_conncetion_header(void)
{
	const char server_class = 0; //int0��Ӧ��char Ϊ48
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
