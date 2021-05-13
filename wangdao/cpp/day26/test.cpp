#include"Thread.h"
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<memory>
using std::cout;
using std::endl;

class MyThread
:public wd::Thread
{
    void run(){
    ::srand(::time(nullptr));
    int cnt=20;
    while(cnt-->0){
        cout<<"sub thread"<<pthread_self()
            <<":number="<<(::rand()%100)<<endl;
        ::sleep(1);
    }
    }
};
void test0(){
    std::unique_ptr<wd::Thread> thread(new MyThread());
    thread->start();
    thread->join();
}
int main(){
    test0();
    return 0;
}
