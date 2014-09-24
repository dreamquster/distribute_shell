#include "YarnRpcRequest.h"

#include <google/protobuf/service.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include "utils/ByteUtils.h"

using namespace google::protobuf;
using namespace google::protobuf::io;


const int RpcCodedMessage::LEN_BYTES = 4;

Logger RpcCodedMessage::LOG = Logger::getInstance(LOG4CPLUS_TEXT("RpcCodedMessage"));

Logger YarnRpcRequest::LOG = Logger::getInstance(LOG4CPLUS_TEXT("YarnRpcRequest"));

RpcCodedMessage::RpcCodedMessage() {
	m_request_bytes = NULL;
}

RpcCodedMessage::~RpcCodedMessage() {
	if (m_request_bytes) {
		delete[] m_request_bytes;
	}
}

int RpcCodedMessage::get_length(void) const {
	return LEN_BYTES + byte_count();
}

const char* RpcCodedMessage::c_str(void) {
	int request_len  = get_length();
	if (NULL == m_request_bytes && 0 < request_len) {
		m_request_bytes = new char[request_len + 1];

		ArrayOutputStream arr_ostream(m_request_bytes, request_len);
		CodedOutputStream coded_ostream(&arr_ostream);

		int net_len  = htonl(byte_count());

		coded_ostream.WriteRaw(&net_len, sizeof(net_len));

		serialize(&coded_ostream);

		m_request_bytes[request_len] = '\0';
		LOG4CPLUS_DEBUG(RpcCodedMessage::LOG, 
			"send rpc message content:" << string(m_request_bytes, m_request_bytes+request_len));
	}
	return m_request_bytes;

}



YarnRpcRequest::YarnRpcRequest(const Message* header, const Message* message) {
	this->m_rpc_header = header;
	this->m_rpc_request = message;
}


YarnRpcRequest::~YarnRpcRequest(void) {

}

int YarnRpcRequest::byte_count() const {
	int total_size = 0;
	if (m_rpc_header) {
		int header_size = m_rpc_header->ByteSize();
		total_size += (CodedOutputStream::VarintSize32(header_size) + header_size);
	} 

	if (m_rpc_request) {
		int request_size = m_rpc_request->ByteSize();
		total_size += CodedOutputStream::VarintSize32(request_size) + request_size;
	} 

	return total_size;
}

bool YarnRpcRequest::serialize(CodedOutputStream* coded_ostream) const  {
	if (m_rpc_header) {
		coded_ostream->WriteVarint32(m_rpc_header->ByteSize());
		m_rpc_header->SerializeToCodedStream(coded_ostream);
	}

	if (m_rpc_request) {
		coded_ostream->WriteVarint32(m_rpc_request->ByteSize());
		m_rpc_request->SerializeToCodedStream(coded_ostream);
	}
	return true;
}

RpcMessageWrapper::RpcMessageWrapper(const Message* header, const RpcCodedMessage* request) {
	this->m_rpc_header = header;
	this->m_rpc_request = request;
}

RpcMessageWrapper::~RpcMessageWrapper() {

}

int RpcMessageWrapper::byte_count() const{
	int total_size = 0;
	if (m_rpc_header) {
		int header_size = m_rpc_header->ByteSize();
		total_size += (CodedOutputStream::VarintSize32(header_size) + header_size);
	} 

	if (m_rpc_request) {
		int request_size = m_rpc_request->byte_count();
		total_size += request_size;
	} 

	return total_size;
}

bool RpcMessageWrapper::serialize(CodedOutputStream* coded_ostream) const  {
	if (m_rpc_header) {
		coded_ostream->WriteVarint32(m_rpc_header->ByteSize());
		m_rpc_header->SerializeToCodedStream(coded_ostream);
	}

	if (m_rpc_request) {
		m_rpc_request->serialize(coded_ostream);
	}

	return true;
}
