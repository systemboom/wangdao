#ifndef _THREADPOOL_H_
#define _THREADPOOL_H_
#include"taskqueue.h"
//#include"thread.h"
#include<vector>

using std::vector;

#include<memory>
using std::unique_ptr;

class Thread;
class Task;

namespace wd{
class Threadpool{
public:
    Threadpool(size_t threadNum,size_t queSize);
    ~Threadpool();

    void start();
    void stop();
    void addTask(Task*);
private:
    Task *getTask();
    void threadFunc();

private:
    size_t _threadNum;
    size_t _queSize;
    vector<unique_ptr<Thread>> _threads;
    TaskQueue _taskque;
};

}//end of namespace wd
#endif
