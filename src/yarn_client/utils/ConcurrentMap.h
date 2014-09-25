#ifndef CONCURRENTMAP_H_ytoewr_325349_ytu
#define CONCURRENTMAP_H_ytoewr_325349_ytu
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/shared_lock_guard.hpp>

#include <map>
using std::map;
typedef boost::shared_mutex RWMutex;
typedef boost::shared_lock<RWMutex> ReadLocker;
typedef boost::unique_lock<RWMutex> WriteLocker;

template<typename K, typename V> class ConcurrentMap {
public:
	void put(const K& key, const V& val) {
		WriteLocker writer(rw_map_mutex);
			m_map[key] = val;
	}

	V get(const K& key) const {
		ReadLocker reader(rw_map_mutex);
			V& ret_val = m_map[key];
		return ret_val;
	}

	void remove(const K& key) {
		WriteLocker writer(rw_map_mutex);
			map<K,V>::iterator it = m_map.find(key);
			if (it != m_map.end()) {
				m_map.erase(it);
			} 
	}
private:
	RWMutex rw_map_mutex;
	map<K,V> m_map;
};
#endif