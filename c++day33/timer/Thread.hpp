 ///
 /// @file    Thread.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-06-24 11:25:56
 ///
 
#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__


#include "Noncopyable.hpp"
#include <pthread.h>

#include <string>
#include <functional>
using std::string;

namespace wd
{

namespace current_thread
{
extern __thread const char * name;
}//end of namespace current_thread

class Thread : Noncopyable
{
	using ThreadCallback = std::function<void()>;
public:
	Thread(ThreadCallback && cb, const string & name = string());

	void start();
	void join();

	virtual ~Thread();
	pthread_t getThreadId() const {	return _pthid;	}
	string getThreadName() const {	return _name;	}

private:
	static void * threadFunc(void*);

private:
	pthread_t        _pthid;
	string		     _name;
	ThreadCallback   _cb;
	bool             _isRunning;
};

}


#endif
