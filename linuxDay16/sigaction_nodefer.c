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

    act.sa_flags = SA_SIGINFO|SA_NODEFER;
    act.sa_sigaction = sigFunc;
    int ret;
    ret = sigaction(SIGINT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction");
    ret = sigaction(SIGQUIT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction");

    while(1);
}

