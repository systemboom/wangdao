#include"Thread.hpp"

namespace wd
{
Thread::Thread(ThreadCallback && cb)
:_pthid(0)
,_isRunning(false)
,_cb(std::move(cb))
{}

Thread::~Thread()
{
    if(_isRunning){
        pthread_detach(_pthid);
        _isRunning=false;
    }
}

void Thread::start()
{
    pthread_create(&_pthid,nullptr,threadFunc,this);
    _isRunning=true;
}

//子线程执行函数(static)
void* Thread::threadFunc(void *arg){
    Thread *pthread=static_cast<Thread*>(arg);
    if(pthread){
        pthread->_cb();
    }
    return nullptr;
}

void Thread::join()
{
    if(_isRunning){
        pthread_join(_pthid,nullptr);//阻塞式函数
        _isRunning=false;
    }
}
}//end of namespace wd
