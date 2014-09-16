SET(SRC applicationclient_protocol.pb.cc
		applicationmaster_protocol.pb.cc
		containermanagement_protocol.pb.cc
		IpcConnectionContext.pb.cc
		ProtobufRpcEngine.pb.cc
		RpcHeader.pb.cc
		Security.pb.cc
		yarn_protos.pb.cc
		yarn_service_protos.pb.cc)

ADD_LIBRARY(yarn_protocal ${SRC})