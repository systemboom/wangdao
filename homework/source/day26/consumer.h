#ifndef _CONSUMER_H_
#define _CONSUMER_H_
#include"thread.h"
namespace wd{

class TaskQueue;
class Consumer
:public Thread{

public:
    Consumer(TaskQueue &);
private:
    void run()override;
    TaskQueue &_taskque;
};
}
#endif
