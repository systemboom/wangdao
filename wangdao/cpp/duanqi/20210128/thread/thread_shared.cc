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

struct Mydata
{
	int x;
	int y;

	Mydata() {	cout << "Mydata()" << endl;	}
	~Mydata() {	cout << "~Mydata()" << endl;}
};

void * threadFunc(void * arg)
{
	Mydata * pmydata = static_cast<Mydata*>(arg);
	pmydata->x = 1000;
	pmydata->y = 2000;

	cout << " threadFunc()  *pmydata:" 
		 << pmydata->x << ","
		 << pmydata->y << endl;

	/* delete pmydata; */
	
	return nullptr;
}

void * threadFunc2(void * arg)
{
	Mydata * pmydata = static_cast<Mydata*>(arg);
	pmydata->x = 1111;
	pmydata->y = 2222;

	cout << " threadFunc2()  *pmydata:" 
		 << pmydata->x << ","
		 << pmydata->y << endl;
	/* delete pmydata; */
	
	return nullptr;
}
 
void test0() 
{
	pthread_t pthid, pthid2;//线程id，标识一个线程
	//堆对象的创建在main线程
	Mydata * pmydata = new Mydata();

	//在主线程看来，pthread_create就是一个函数
	if(pthread_create(&pthid, nullptr, threadFunc, (void*)pmydata) != 0) {
		perror("pthread_create");
	}

	if(pthread_create(&pthid2, nullptr, threadFunc2, (void*)pmydata) != 0) {
		perror("pthread_create");
	}
	pmydata->x = 1;
	pmydata->y = 2;

	cout << "sub pthid: " << pthid << endl;
	
	pthread_join(pthid, nullptr);
	pthread_join(pthid2, nullptr);

	delete pmydata;
}

int main(int argc, char ** argv)
{
	test0();
	return 0;
}

