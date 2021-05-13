#ifndef _TASKQUEUE_H_
#define _TASKQUEUE_H_
#include"mutelock.h"
#include"condition.h"
#include<queue>
using std::queue;

namespace wd{
class TaskQueue{
public:
    TaskQueue(size_t);
    bool empty()const;
    bool full()const;
    void push(int x);
    int pop();

private:
    size_t _queSize;
    queue<int> _que;
    MutexLock _mutex;
    Condition _notEmpty;
    Condition _notFull;
};
}
#endif
