//******************************************************
//
// Author       : tetuso 
// Last modified: 2021-02-07 15:05
// Email        : 309114982.com
// blog         : https://blog.csdn.net 
// Filename     : Thread.hpp
// Description  : 
// ******************************************************
#ifndef _WD_THREAD_H_
#define _WD_THREAD_H_

#include<functional>
#include"Nocopyable.hpp"
#include<pthread.h>

namespace wd{

class Thread:Noncopyable
{
    using ThreadCallback=std::function<void()>;
public:
    Thread(ThreadCallback && cb);
    
    void start();
    void join();

    virtual ~Thread();

private:
    static void *threadFunc(void*);
private:
    pthread_t       _pthid;
    bool            _isRunning;
    ThreadCallback  _cb;
};
}

#endif

