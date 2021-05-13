//#include...实现文件的第一行必须要是相应的头文件，不能是其他的头文件
#include"Thread.h"

namespace wd{
Thread::Thread():_pthid(0),_isRunning(false){}

void Thread::start(){
    pthread_create(&_pthid,nullptr,threadFunc,this);
    _isRunning=true;
}
//子线程执行函数(static)
void *Thread::threadFunc(void *arg){
    Thread *pthread=static_cast<Thread*>(arg);
//Thread为static，是没有this指针的，但这个地方我们需要用this调用run()，所以将pthread_create的第四个参数设置为this，
//如果pthread有参数，则调用run()
    if(pthread){
        pthread->run();
    }
    return nullptr;
}
void Thread::join(){
    if(_isRunning){
        pthread_join(_pthid,nullptr);//阻塞式函数
        _isRunning=false;
    }
}
Thread::~Thread(){
    //既然已经调用析构函数，说明这个对象马上要被销毁了，即使这个线程依然在运行，此时也要把线程控制权交还给系统，由系统自动回收
    if(_isRunning){
        pthread_detach(_pthid);
        _isRunning=false;
    }
}
}

