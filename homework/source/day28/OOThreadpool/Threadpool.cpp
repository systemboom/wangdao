//******************************************************
//
// Author       : tetuso 
// Last modified: 2021-02-01 22:07
// Email        : 309114982.com
// blog         : https://blog.csdn.net 
// Filename     : Threadpool.cpp
// Description  : 
// ******************************************************
#include"Threadpool.h"

namespace wd{
Threadpool::Threadpool(size_t threadNum,size_t queSize)
    :_threadNum(threadNum)
    ,_queSize(queSize)
    ,_threads()
    ,_taskque(_queSize)
    {_threads.reserve(_threadNum);}

void Threadpool::start(){
    for(auto idx=0;idx=_threadNum;++idx){
        unique_ptr<Thread>up(new WorkerThread());
        _threads.push_back(std::move(up));
    }
} 
}
