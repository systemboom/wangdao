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

int gTicket = 1000000;


void * threadFunc(void * arg)
{
    int num=*(int *)arg;
	cout << " threadFunc() number:"<<num << endl;
	//在子线程内部调用pthread_self, 获取子线程的线程id
	cout << " sub threadid : " << pthread_self() << endl;

	sleep(10);
	cout << " sub thread exit" << endl;
	return nullptr;
}

 
void test0() 
{
	pthread_t pthid, pthid2;//线程id，标识一个线程
    int number=100;

	//在主线程看来，pthread_create就是一个函数
	if(pthread_create(&pthid, nullptr, threadFunc,& number) != 0) {
		perror("pthread_create");
	}
#if 0
	if(pthread_create(&pthid2, nullptr, threadFunc, NULL) != 0) {
		perror("pthread_create");
	}
#endif
	cout << "sub pthid: " << pthid << endl;
	
	//在本线程内部获取自己的线程id
	cout << "main pthread id :" << pthread_self() << endl;
	
	cout << ">> test0() 代表的是主线程" << endl;

	
	// 主线程等待子线程运行结束
	// pthread_join 是一个阻塞式函数,
	// 当子线程没有退出时，就一直阻塞，直到子线程运行结束,
	// 该函数才返回
	pthread_join(pthid, nullptr);
	pthread_join(pthid2, nullptr);
}

// 注意: 创建子线程时，如果main函数退出了，子线程也会被回收的
//		 子线程是无法得到执行的
 
int main(int argc, char ** argv)
{
	test0();

	int number = 10;
	cout << "number : " << number << endl;
	//要求: main线程需要等待子线程执行结束，才能正常退出
	while(1);//一直在使用CPU的时间片, 意味着main线程并没有进入等待状态
	return 0;
}

