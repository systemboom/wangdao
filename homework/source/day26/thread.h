
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__
#include"Noncopyable.h"
#include <pthread.h>

namespace wd{

class Thread
:Noncopyable{
public:
	Thread();
	void start();
	void join();

	virtual ~Thread();

private:
	
	virtual void run() = 0;

	static void * threadFunc(void * arg);

private:
	pthread_t _pthid;
	bool _isRunning;
};

}


#endif

