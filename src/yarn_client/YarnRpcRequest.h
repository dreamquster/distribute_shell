#ifndef YARNRPC_REQUEST_H_yotewt_53532_
#define YARNRPC_REQUEST_H_yotewt_53532_
#include "yarn_protocal/RpcHeader.pb.h"
#include <google/protobuf/io/coded_stream.h>
#include "common.h"

#include "yarn_protocal/ProtobufRpcEngine.pb.h"

using namespace hadoop::common;
using google::protobuf::Message;
using google::protobuf::io::CodedOutputStream;


class RpcCodedMessage{
public:
	static const int LEN_BYTES; 
	static Logger LOG;

	RpcCodedMessage();
	virtual ~RpcCodedMessage();
	virtual bool serialize(CodedOutputStream* coded_ostream) = 0;
	virtual int byte_count(void) const = 0 ;

	int get_length(void) const;
	const char* c_str(void);
private:
	char* m_request_bytes;
};

/************************************************************************/
/* Yarn request has 4 chars to represent the length of request          */ 
/************************************************************************/
class YarnRpcRequest: public RpcCodedMessage
{
public:
	static Logger LOG;

	YarnRpcRequest(Message* header, Message* message);
	virtual ~YarnRpcRequest(void);	

	bool serialize(CodedOutputStream* coded_ostream);
	
	int byte_count(void) const;

private:
	Message* m_rpc_header;
	Message* m_rpc_request;
	
};




class RpcMessageWrapper:public RpcCodedMessage
{
public:
	RpcMessageWrapper(Message* header, RpcCodedMessage* request);
	virtual ~RpcMessageWrapper();

	bool serialize(CodedOutputStream* coded_ostream);

	int byte_count(void) const;
private:
	Message* m_rpc_header;
	RpcCodedMessage* m_rpc_request;
	int m_request_len;
};


#endif


