#ifndef RESOUCELOCK_H_feyre_533254_
#define RESOUCELOCK_H_feyre_533254_
#include <pthread.h>
class MethodLocker {
public:
	MethodLocker(pthread_mutex_t* m_mutex) {
		mp_mutex = m_mutex;
		pthread_mutex_lock(mp_mutex);
	} 
	virtual ~MethodLocker() {
		pthread_mutex_unlock(mp_mutex);
	}
private:
	pthread_mutex_t* mp_mutex;
};

class ResourceLock
{
public:
	ResourceLock(void);
	virtual ~ResourceLock(void);

	void wait();
	void signal();

	pthread_mutex_t* get_obj_mutex() ;
private:
	pthread_mutex_t m_mutex;
	pthread_mutex_t m_obj_mutex;
	pthread_cond_t m_cond;
};

#endif


