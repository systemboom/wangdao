#include <func.h>

void sigFunc(int signum,siginfo_t* pInfo,void *p)
{
    printf("before sleep %d is comming\n",signum);
    sleep(3);//模拟信号处理函数里做一些工作
    printf("after sleep %d is comming\n",signum);
}

int main()
{
    struct sigaction act;
    bzero(&act,sizeof(act));

    act.sa_flags = SA_SIGINFO|SA_NODEFER;//递归处理信号
    act.sa_sigaction = sigFunc;
    sigemptyset(&act.sa_mask);//清空信号集合set
   
    sigaddset(&act.sa_mask,SIGQUIT);//增加一个SIGQUIT信号
    //希望在信号处理函数中不会被3号信号打断
    
    int ret;
    ret = sigaction(SIGINT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction");
    //信号处理函数执行完毕之后，仍然会被3号信号打断

    while(1);
}
