#include "ResourceLock.h"


ResourceLock::ResourceLock(void) {
	m_cond = PTHREAD_COND_INITIALIZER;
	m_mutex = PTHREAD_MUTEX_INITIALIZER;
}


ResourceLock::~ResourceLock(void) {
	pthread_mutex_destroy(&m_mutex);
	pthread_cond_destroy(&m_cond);
}

void ResourceLock::wait() {
	pthread_mutex_lock(&m_mutex);
		pthread_cond_wait(&m_cond, &m_mutex);
	pthread_mutex_unlock(&m_mutex);
}

void ResourceLock::signal() {
	pthread_mutex_lock(&m_mutex);
		pthread_cond_signal(&m_cond);
	pthread_mutex_unlock(&m_mutex);
}

pthread_mutex_t* ResourceLock::get_obj_mutex()  {
	return &m_obj_mutex;
}