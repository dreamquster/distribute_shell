#ifndef YARNRPC_REQUEST_H_yotewt_53532_
#define YARNRPC_REQUEST_H_yotewt_53532_
#include "yarn_protocal/RpcHeader.pb.h"
using namespace hadoop::common;
using google::protobuf::Message;

class YarnRpcRequest
{
public:
	YarnRpcRequest(void);
	~YarnRpcRequest(void);
private:
	RpcRequestHeaderProto m_rpc_header;
	Message* m_rpc_request;
};
#endif


