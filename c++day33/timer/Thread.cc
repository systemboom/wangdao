 ///
 /// @file    Thread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-06-24 11:32:58
 ///

#include "Thread.hpp"

namespace wd
{

namespace current_thread
{
__thread const char * name = "wd thread";
}


struct ThreadData
{
	using ThreadCallback = std::function<void()>;

	ThreadData(const string & name, const ThreadCallback & cb)
	: _name(name)
	, _cb(cb)
	{}

	//一个线程要调用的方法
	void runInThread()
	{
		wd::current_thread::name = (_name == string() ?"wd thread" : _name.c_str());
		if(_cb) 
			_cb();
	}

	string			_name;
	ThreadCallback	_cb;
};


Thread::Thread(ThreadCallback && cb, const string & name)
: _pthid(0)
, _name(name)
, _cb(std::move(cb))
, _isRunning(false)
{
}

Thread::~Thread()
{
	if(_isRunning) {
		pthread_detach(_pthid);	
		_isRunning = false;
	}
}

void Thread::start()
{
	ThreadData * pdata = new ThreadData(_name, _cb);
	pthread_create(&_pthid, nullptr, threadFunc, pdata);
	_isRunning = true;
}

//子线程执行函数(static)
void * Thread::threadFunc(void * arg) {
	ThreadData * pdata = static_cast<ThreadData*>(arg);
	if(pdata) {
		pdata->runInThread();
	}

	delete pdata;
	return nullptr;
}

void Thread::join()
{
	if(_isRunning) {
		pthread_join(_pthid, nullptr);//阻塞式函数
		_isRunning = false;
	}
}

}//end of namespace wd
