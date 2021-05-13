#ifndef _PRODUCER_H_
#define _PRODUCER_H_ 

#include"thread.h"

namespace wd{

class TaskQueue;

class Producer
:public Thread{
public:
    Producer(TaskQueue &);
    
private:
    void run()override;
    TaskQueue &_taskque;
};

}
#endif
