#include"consumer.h"
#include"taskqueue.h"

#include<unistd.h>
#include<iostream>
using std::cout;
using std::endl;
namespace wd{
Consumer::Consumer(TaskQueue &taskque)
    :_taskque(taskque)
    {}
void Consumer::run(){
    int cnt=10;
    while(cnt-->0){
        int num=_taskque.pop();
        cout << "sub thread " << pthread_self()
				 << " consume a number: " << num << endl;
    ::sleep(2);
    }
}
}
