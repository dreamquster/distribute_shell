#ifndef LOGUTILS_H_goewrouyetw_43432
#define LOGUTILS_H_goewrouyetw_43432
#include "memory.h"
#include <google/protobuf/service.h>
using google::protobuf::uint8;
using google::protobuf::uint32;

namespace ByteUtils {

	static const int endian = 1;

	inline static bool is_bigendian () {
		return ((*(char*) &endian) == 0);
	}

	inline static bool is_littlendbian() {
			return ((*(char*) &endian) == 1);
	}

	inline static int to_bigendian_int32(int val) {
		if(is_littlendbian()) {
			int res = 0;
			char* byte_res = (char*)(&res); 
			byte_res[0] = (val >> 24) & 0xFF;
			byte_res[1] = (val >> 16) & 0xFF;
			byte_res[2] = (val >> 8) & 0xFF;
			byte_res[3] = (val >> 0) & 0xFF;
			return res;
		} //else

		return val;
	}


	static const int kMaxVarintBytes = 10;
	static const int kMaxVarint32Bytes = 5;
	//copy from protobuf/coded_stream.cc anonymous namespace to assist parse the length of response
	inline static const uint8* ReadVarint32FromArray(const uint8* buffer, uint32* value) {
		// Fast path:  We have enough bytes left in the buffer to guarantee that
		// this read won't cross the end, so we can skip the checks.
		const uint8* ptr = buffer;
		uint32 b;
		uint32 result;

		b = *(ptr++); result  = (b & 0x7F)      ; if (!(b & 0x80)) goto done;
		b = *(ptr++); result |= (b & 0x7F) <<  7; if (!(b & 0x80)) goto done;
		b = *(ptr++); result |= (b & 0x7F) << 14; if (!(b & 0x80)) goto done;
		b = *(ptr++); result |= (b & 0x7F) << 21; if (!(b & 0x80)) goto done;
		b = *(ptr++); result |=  b         << 28; if (!(b & 0x80)) goto done;

		// If the input is larger than 32 bits, we still need to read it all
		// and discard the high-order bits.
		for (int i = 0; i < kMaxVarintBytes - kMaxVarint32Bytes; i++) {
			b = *(ptr++); if (!(b & 0x80)) goto done;
		}

		// We have overrun the maximum size of a varint (10 bytes).  Assume
		// the data is corrupt.
		return NULL;

done:
		*value = result;
		return ptr;
	}


};
#endif