#ifndef _CONDITION_H_
#define _CONDITION_H_

#include"Noncopyable.h"

#include<pthread.h>
namespace wd{
class MutexLock;
class Condition
:Noncopyable{
public:
    Condition(MutexLock &Mutex);
    ~Condition();

    void wait();
	void notify();
	void notifyall();
private:
    MutexLock& mutex_;
    pthread_cond_t pcond_;
};
}
#endif
