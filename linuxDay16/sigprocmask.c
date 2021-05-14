#include <func.h>

int main()
{

    sigset_t mask;
    sigset_t pending;
    sigemptyset(&mask);

    // 希望在关键代码执行的时候，避免被3号信号打断
    //将3号信号添加到阻塞信号集合
    sigaddset(&mask,SIGQUIT);
    
    sigprocmask(SIG_BLOCK,&mask,NULL);
    //为了模拟关键代码的执行
    sleep(5);
    //sigpending系统调用会到进程的结构体里把
    //挂起的信号的集合拿出来到pending里
    sigpending(&pending);
    //此时SIGQUIT是被挂起的,sigismember的返回值为1
    printf("ispending =%d\n",sigismember(&pending,SIGQUIT));
    // 关键代码执行完毕之后，解除对3号信号的阻塞
    sigprocmask(SIG_UNBLOCK,&mask,NULL);
    //解除阻塞之后，挂起的3号信号会被处理

 
    while(1);
}

