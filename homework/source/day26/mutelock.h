#ifndef _MUTELOCK_H_
#define _MUTELOCK_H_
#include<pthread.h>
#include"Noncopyable.h"

namespace wd{

class MutexLock
:Noncopyable
{
public:
    MutexLock();
    ~MutexLock();
    
    pthread_mutex_t* getPthreadMutex();
    void lock();
    void unlock();
    //MutexLock(const MutexLock&)=delete;
    //MutexLock&operator=(const MutexLock&)=delete;
private:
    pthread_mutex_t mutex_;
    bool holder;
};

class MutexLockGuard{
public: 
MutexLockGuard(MutexLock & mutex)
	: mutex_(mutex){	
        mutex_.lock();	}

	~MutexLockGuard(){
        mutex_.unlock();	}
    
private:
    MutexLock &mutex_;
};

}


#endif
