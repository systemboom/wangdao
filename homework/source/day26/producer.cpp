#include"producer.h"
#include"taskqueue.h"

#include<cstdio>
#include<ctime>
#include <unistd.h>

#include<iostream>
using std::cout;
using std::endl;

namespace wd{

Producer::Producer(TaskQueue &taskque)
    :_taskque(taskque)
    {}

void Producer::run(){
    int count = 10;
    while(count-- > 0) {
        ::srand(::time(nullptr));
        int number = ::rand() % 100;
        _taskque.push(number);
        cout << "sub thread " << pthread_self()
            << " produce a number: " << number << endl;
        ::sleep(1);
    }
}

}
