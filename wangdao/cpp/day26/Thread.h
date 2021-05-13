#ifndef _WD_THREAD_H_
#define _WD_THREAD_H_
//不相关的头文件不要堆进来， ==>Keep your code clean
#include<pthread.h>

namespace wd{

class Thread{
public:
    Thread();
    //当一个类有子类时，该类的析构函数必须是虚函数，否则会有资源释放不完全的情况
   void start();
   void join();
   //threadFunc函数其实有两个参数，其隐含了一个this指针，但这里不能要this，所以把threadFunc设置成静态的
   
    virtual ~Thread();
    
private:
   static void *threadFunc(void *);
    virtual void run()=0;

private:
    pthread_t _pthid;
    bool _isRunning;
};

}
#endif
