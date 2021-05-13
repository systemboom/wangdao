#include"taskqueue.h"
namespace wd{
TaskQueue::TaskQueue(size_t size)
    :_queSize(size)
    ,_que()
    ,_mutex()
    ,_notEmpty(_mutex)
    ,_notFull(_mutex)
    {}

bool TaskQueue::full()const{
    return _que.size()==_queSize;
}

bool TaskQueue::empty()const{
    return _que.size()==0;
}

void TaskQueue::push(int x){
    MutexLockGuard autolock(_mutex);
    while(full()){
       _notFull.wait(); 
    }
    _que.push(x);
    _notEmpty.notify();
    
}
int TaskQueue::pop(){
    MutexLockGuard autolock(_mutex);
    while(empty()){
        _notEmpty.wait();
    }
    int num=_que.front();
    _que.pop();
    _notFull.notify();
    return num;
}

}
