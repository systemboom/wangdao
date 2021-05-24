 ///
 /// @file    TestTimer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-07-03 11:31:16
 ///
 
#include "TimerThread.hpp"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <memory>
#include <functional>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::bind;

void process()
{
	::srand(::time(nullptr));
	int number = ::rand() % 100;
	cout << "number = " << number << endl;
}

void test0()
{
	unique_ptr<wd::Timer> timer(new wd::Timer(process, 3, 6));	
	unique_ptr<wd::Thread> timerThread(new wd::Thread(
		bind(&wd::Timer::start, timer.get())));

	timerThread->start();

	::sleep(10);
	timer->stop();
	timerThread->join();
}

void test1()
{
	unique_ptr<wd::TimerThread> timer(
		new wd::TimerThread(process, 3, 6));

	timer->start();//在一个子线程中开始运行

	::sleep(20);
	timer->stop();
}
 
int main(void)
{
	/* test0(); */
	test1();
	return 0;
}
