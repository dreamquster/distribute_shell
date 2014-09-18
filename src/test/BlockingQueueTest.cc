#ifndef BLOCKINGQUEUE_TEST_H_eyoew_532q_te
#define BLOCKINGQUEUE_TEST_H_eyoew_532q_te
#include <gtest/gtest.h>
#include "pthread.h"

#define private public

#include "utils/BlockingQueue.cc"
using namespace std;


class BlockingQueueTest: public testing::Test {
public:	
	static BlockingQueue<int> blocking_queue;//declearation
	static void* read_queue(void* arg) {
		vector<int>* pvect = (vector<int>*)arg;
		if (pvect) {
			cout<<"pvect"<<pvect << "with size" << pvect->size()<<endl;
			for (size_t i = 0; i < pvect->size(); ++i) {
				int exp_val = (*pvect)[i];
				cout<<"blocking_quueue size: "<<blocking_queue.m_queue.size()<<endl;
				int write_val = blocking_queue.pop_front();				
				cout<<"exp_val:"<<exp_val<<" write_val:"<<write_val<<endl;
				EXPECT_EQ(exp_val, write_val);
			}
		}
		return NULL;
	}

	static void* write_queue(void* arg) {
		vector<int>* pvect = (vector<int>*)arg;
		if (pvect) {
			for (size_t i = 0; i < pvect->size(); ++i) {
				int val = (*pvect)[i];
				cout<<"write_queue data :"<<val<<endl;
				blocking_queue.push_back(val);
			}
		}
		return NULL;
	}

protected:

};

BlockingQueue<int> BlockingQueueTest::blocking_queue;

TEST_F(BlockingQueueTest, GetFetchConflict) {
	int arr[] = {1, 3, 5, 7, 11, 110};
	vector<int> test_vect(arr, arr + sizeof(arr)/sizeof(arr[0]));
	pthread_t read_th;
	pthread_create(&read_th, NULL, BlockingQueueTest::read_queue, &test_vect);
	pthread_t write_th;
	pthread_create(&write_th, NULL, BlockingQueueTest::write_queue, &test_vect);

	int a = 5;
	int* ret = &a;
	pthread_join(write_th, NULL);
	cout<<"write_th return result:"<<*ret<<"0 success"<<endl;
	pthread_join(read_th, NULL);
	cout<<"read_th return result:"<<*ret<<"0 success"<<endl;
}

#endif