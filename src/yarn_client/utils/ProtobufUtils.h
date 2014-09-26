#ifndef  PROTOBUF_H_UTILS_fefewa9_439
#define PROTOBUF_H_UTILS_fefewa9_439

#include "../yarn_protocal/RpcHeader.pb.h"

namespace ProtobufUtils {

	static RpcRequestHeaderProto make_rpc_request_header(RpcKindProto rpc_kind,
		RpcRequestHeaderProto_OperationProto oper, int call_id, int retry_count, char* client_id) {
			RpcRequestHeaderProto header;
			header.set_rpckind(rpc_kind);
			header.set_rpcop(oper);
			header.set_retrycount(retry_count);
			header.set_callid(call_id);
			header.set_clientid(client_id);
			return header;
	}

}
#endif