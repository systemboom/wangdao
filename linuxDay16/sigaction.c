#include <func.h>

void sigFunc(int signum,siginfo_t* pInfo,void *p)
{
    printf("before sleep %d is comming\n",signum);
    //注意这里要加\n，不然信号来了在终端上看不到
    sleep(3);//模拟信号处理函数里做一些工作
    printf("after sleep %d is comming\n",signum);
}

int main()
{
    struct sigaction act;
    bzero(&act,sizeof(act));

    act.sa_flags = SA_SIGINFO;
    //SA_SIGINFO表示sa_sigaction函数指针有效
    act.sa_sigaction = sigFunc;
    //新类型的信号处理函数指针
    int ret;
    //跟signal(SIGINT,sigFunc)效果一样
    ret = sigaction(SIGINT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction");
    ret = sigaction(SIGQUIT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction");

    while(1);
}

