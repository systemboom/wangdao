//******************************************************
//
// Author       : tetuso 
// Last modified: 2021-02-01 21:18
// Email        : 309114982.com
// blog         : https://blog.csdn.net 
// Filename     : Task.h
// Description  : 
// ******************************************************
#ifndef _TASK_H_
#define _TASK_H_

namespace wd{
class TaskQueue;
class Task{
public:
    virtual void process()=0;
};
}
#endif
