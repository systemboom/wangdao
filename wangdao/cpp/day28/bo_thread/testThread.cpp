#include"Thread.hpp"
using std::bind;

#include<iostream>
using std::cout;
using std::endl;

#include<stdlib.h>
#include<time.h>

#include<unistd.h>

#include<memory>
using std::unique_ptr;

void process()
{
    srand(time(nullptr));
    while(1){
        int number=::rand()%100;
        cout<<">>sub thread"<<pthread_self()
        <<"number:"<<number<<endl;
        sleep(1);
    }
}
struct Task{
    void process()
    {
        cout<<">> Task::process()"<<endl;
        ::process();
  
    }
};

void test0(){
    /* unique_ptr<wd::Thread> subthread(new wd::Thread(process)); */
    unique_ptr<wd::Thread> subthread(
          new wd::Thread(
                bind(&Task::process,Task())));    
    subthread->start();
    subthread->join();
}

int main()
{
    test0();
    return 0;
}
