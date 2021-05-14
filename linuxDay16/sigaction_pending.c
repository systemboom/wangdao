#include <func.h>

void sigFunc(int signum,siginfo_t* pInfo,void *p)
{
    printf("before sleep %d is comming\n",signum);
    sleep(3);//模拟信号处理函数里做一些工作
    sigset_t set;
    sigpending(&set);
    if(sigismember(&set,SIGQUIT))
    {
        printf("SIGQUIT is pending\n");
    }
    else
    {
        printf("SIGQUIT is not pending\n");
    }

    printf("after sleep %d is comming\n",signum);
}

int main()
{
    struct sigaction act;
    bzero(&act,sizeof(act));

    act.sa_flags = SA_SIGINFO|SA_NODEFER;
    //希望在信号处理函数中不会被3号信号打断
    //在sigFunc执行的时候，不会被3号信号打断
    act.sa_sigaction = sigFunc;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask,SIGQUIT);
    int ret;
    ret = sigaction(SIGINT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction");
    //信号处理函数执行完毕之后，仍然会被3号信号打断

    while(1);
}
