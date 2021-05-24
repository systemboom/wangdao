#include <func.h>

void sigFunc(int signum,siginfo_t *pInfo,void* p)
{
    printf("send signal pid=%d,uid=%d\n",pInfo->si_pid,pInfo->si_uid);
    //打印发送信号的进程号、用户标识号
}

int main()
{
    struct sigaction act;
    bzero(&act,sizeof(act));

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = sigFunc;

    int ret;
    ret = sigaction(SIGINT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction");

    while(1);

    return 0;
}

