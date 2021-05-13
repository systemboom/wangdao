//******************************************************
//
// Author       : tetuso 
// Last modified: 2021-02-01 22:42
// Email        : 309114982.com
// blog         : https://blog.csdn.net 
// Filename     : WorkerThread.h
// Description  : 
// ******************************************************
#ifndef _WD_WORKERTHREAD_H_
#define _WD_WORKERTHREAD_H

#include"thread.h"

namespace wd{
class Threadpool;
class WorkThread
:public Thread{
public:
    WorkderThread(Threadpool & threadpool);
private:
    void run()override;
private:
    Threadpool &_threadpool;

};
}
#endif
