#ifndef BLOCKINGQUEUE_H_eyoew_532q_
#define BLOCKINGQUEUE_H_eyoew_532q_
#include <deque>
#include "pthread.h"
using std::deque;


template<typename T>class BlockingQueue
{
public:
	BlockingQueue(void) {
		m_mutex = PTHREAD_MUTEX_INITIALIZER;
		m_cond = PTHREAD_COND_INITIALIZER;
	}

	virtual ~BlockingQueue(void) {
		pthread_mutex_destroy(&m_mutex);
		pthread_cond_destroy(&m_cond);
	}

	void push_back(const T& val) {
		pthread_mutex_lock(&m_mutex);
			m_queue.push_back(val);
			pthread_cond_signal(&m_cond);
		pthread_mutex_unlock(&m_mutex);
	}

	T pop_front(void) {
		while (true) {
			pthread_mutex_lock(&m_mutex);				
				if (!m_queue.empty()) {
					T val = m_queue.front();
					m_queue.pop_front();
					pthread_mutex_unlock(&m_mutex);
					return val;
				} else {
					pthread_cond_wait(&m_cond, &m_mutex);
				}
			pthread_mutex_unlock(&m_mutex);
		}		
	}

private:
	pthread_mutex_t m_mutex;
	pthread_cond_t m_cond;
	deque<T> m_queue;
};

#endif


