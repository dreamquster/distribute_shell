#ifndef CONST_VAIABLE_H_ttert_33da_
#define CONST_VAIABLE_H_ttert_33da_
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>  

#define ERR_RETURN -1


namespace NetUtils {
	static const int INVALID_SOCKET = ~0;

	static const Logger LOG = Logger::getInstance(LOG4CPLUS_TEXT("NetUtils"));

	static int write_all(int fildes, char *buf, unsigned int nbyte)
	{
		int ret;
		char *ptr;

		for (ptr = buf; nbyte; ptr += ret, nbyte -= ret) {
			ret = write(fildes, ptr, nbyte);
			if (ret < 0) {
				if (errno == EINTR)
					continue;
				return(ret);
			} else if (ret == 0) {
				return(ptr-buf);
			}
		}

		return(ptr-buf);
	}


	static void receive_rpc_response(int& server_fd, RpcResponseHeaderProto& header, Message& response) {
		int response_len = 0;
		recv(server_fd, (char*)&response_len, sizeof(response_len), 0);
		response_len = ntohl(response_len);
		if (0 < response_len) {
			boost::scoped_array<char> buffer(new char[response_len]);
			int buf_pos = 0;
			recv(server_fd, buffer.get(), response_len, 0);

			uint32 header_len = 0; 
			ByteUtils::ReadVarint32FromArray((uint8*)buffer.get(), &header_len);
			buf_pos += CodedOutputStream::VarintSize32(header_len);
			if (0 < header_len) {
				header.ParseFromArray((void*)(buffer.get() + buf_pos), header_len);
				buf_pos += header_len;

				RpcResponseHeaderProto::RpcStatusProto status = header.status();
				if (status == RpcResponseHeaderProto::SUCCESS) {
					LOG4CPLUS_INFO(LOG, "call successed");

					uint32 body_len = 0;
					ByteUtils::ReadVarint32FromArray((uint8*)(buffer.get() + buf_pos), &body_len);
					buf_pos += CodedOutputStream::VarintSize32(body_len);
					response.ParseFromArray((void*)(buffer.get() + buf_pos), body_len);
				}
			}
		}
	}
}

namespace RpcConstant {

	static const int INVALID_TRIES = -1;

	static const char HEADER[] = "hrpc";

	static const char CURRENT_VERSION = 9;

	static const char DUMMY_CLIENT_ID = "";

	static const int SASL_CALLID = -33;

	static const int DEFAULT_CALLID = 0;

}

#endif