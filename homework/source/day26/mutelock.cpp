#include"mutelock.h"
#include<cstdio>
namespace wd{
MutexLock::MutexLock():holder(false){
    if(pthread_mutex_init(&mutex_,nullptr)!=0){
        perror("pthread_mutex_init");
    }
}

void MutexLock::lock(){
    if(pthread_mutex_lock(&mutex_)!=0){
        perror("pthread_mutex_lock");
    }
    holder=true;
}

pthread_mutex_t* MutexLock::getPthreadMutex(){
    return &mutex_;
}
void MutexLock::unlock(){
    if(pthread_mutex_unlock(&mutex_)!=0){
        perror("pthread_mutex_unlock");
    }
    holder=false;
}

MutexLock::~MutexLock(){
    if(pthread_mutex_destroy(&mutex_)!=0){
        perror("pthread_mutex_destroy");
    }
}
}
