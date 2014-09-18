#ifndef LOGUTILS_H_goewrouyetw_43432
#define LOGUTILS_H_goewrouyetw_43432

static const int endian = 1;

namespace ByteUtils {

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

};
#endif