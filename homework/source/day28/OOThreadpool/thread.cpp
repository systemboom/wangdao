

#include <stdio.h>
#include <errno.h>

#include "thread.h"
 
namespace wd{

Thread::Thread()
: _pthid(0)
, _isRunning(false)
{}

void Thread::start(){
	if(pthread_create(&_pthid, nullptr, threadFunc, this) != 0) {
		perror("pthread_create");
		return ;
	}	
	_isRunning = true;
}


void Thread::join()
{
	if(_isRunning) {
		pthread_join(_pthid, nullptr);
	    _isRunning = false;
    }

}

Thread::~Thread(){
	if(_isRunning) {
		
		pthread_detach(_pthid);
        _isRunning=false;
    }
}


void * Thread::threadFunc(void * arg){
	Thread * pthread = static_cast<Thread*>(arg);
	
	if(pthread) {
		pthread->run();
	}
	return nullptr;
}
 
}

