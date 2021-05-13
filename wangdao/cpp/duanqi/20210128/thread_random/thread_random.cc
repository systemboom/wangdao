
 ///
 /// @file    threadtest.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-28 16:53:13
 ///


#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

#include <iostream>
using std::cout;
using std::endl;


//多线程时 ，每个线程的执行是乱序的
//
//需求: 希望两个窗口交替卖票
//问题的点： 意味着两个线程需要互相通知对方 ==> 条件变量
//
//条件:
//	当flag为true的时候，让窗口1卖票
//	当flag为false的时候，让窗口2卖票
//
int gTicket = 1000;
pthread_mutex_t gMutex;
pthread_mutex_t gMutex2;//锁是可以创建多个的
pthread_cond_t gCond;
bool flag = false;

void * windows1(void * arg)
{
	int count = 500;
	while(count-- > 0) {
		pthread_mutex_lock(&gMutex);//加锁
		//	当flag为true的时候，让窗口1卖票
		while(flag == false) { // 防止"虚假唤醒" (面试常考点)
			//1. 上半部：当调用pthread_cond_wait方法时，会阻塞当前线程,
			//等待条件成立； 但是在阻塞之前，需要解锁，否则，会发生死锁
			pthread_cond_wait(&gCond, &gMutex);
			//4. 下半部: 当收到窗口2的通知时，线程1会被唤醒，
			//唤醒之后的第一件事儿是加锁; 如果加锁成功，那就继续往下执行
			//
			//疑问点解释: 下半部的加锁操作是在wait函数内部进行
		}

		// 执行卖票操作
		--gTicket;// 临界资源
		flag = false;
		cout << " sub threadid " << pthread_self()
			 << " left ticks " << gTicket << endl;
		pthread_mutex_unlock(&gMutex);

		//通知窗口2卖票
		//该函数的作用,正常情况下是激活一个线程；但也有概率激活多个线程
		pthread_cond_signal(&gCond);
	}
	return nullptr;
}

void * windows2(void * arg)
{
	int count = 500;
	while(count-- > 0) {
		pthread_mutex_lock(&gMutex);
		//当flag为false的时候，让窗口2卖票
		while(flag == true) {
			pthread_cond_wait(&gCond, &gMutex);
		}

		//2. 执行卖票
		--gTicket;
		flag = true;
		cout << " sub threadid " << pthread_self()
			 << " left ticks " << gTicket << endl;
		pthread_mutex_unlock(&gMutex);

		//3. 通知窗口1卖票
		pthread_cond_signal(&gCond);
	}
	return nullptr;
}

void test0()
{
	//char * p;//未初始化，就是野指针

	pthread_t pthid, pthid2;//线程id，标识一个线程

	//初始化互斥锁
	pthread_mutex_init(&gMutex, nullptr);

	//初始化条件变量
	pthread_cond_init(&gCond, nullptr);

	//在主线程看来，pthread_create就是一个函数
	if(pthread_create(&pthid, nullptr, windows1, NULL) != 0) {
		perror("pthread_create");
	}

	if(pthread_create(&pthid2, nullptr, windows2, NULL) != 0) {
		perror("pthread_create");
	}

	pthread_join(pthid, nullptr);
	pthread_join(pthid2, nullptr);


	//销毁互斥锁
	pthread_mutex_destroy(&gMutex);
	//销毁条件变量
	pthread_cond_destroy(&gCond);
}


int main(int argc, char ** argv)
{
	test0();
	return 0;
}

