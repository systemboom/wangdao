#include"condition.h"
#include"mutelock.h"
#include<cstdio>

namespace wd{
Condition:: Condition(MutexLock &mutex):mutex_(mutex){
    if(pthread_cond_init(&pcond_,nullptr)!=0){
        perror("pthread_cond_init");
    }
}
void Condition::wait(){
    if(pthread_cond_wait(&pcond_,mutex_.getPthreadMutex())!=0){
        perror("pthread_cond_wait");
    }
}
void Condition::notify(){
    if(pthread_cond_signal(&pcond_)!=0){
        perror("pthread_cond_signal");
    }
}
void Condition::notifyall(){
    if(pthread_cond_broadcast(&pcond_)!=0){
        perror("pthread_cond_broadcast");
    }
}
Condition::~Condition(){
    if(pthread_cond_destroy(&pcond_)!=0){
        perror("pthread_cond_destroy");
    }
}
}
