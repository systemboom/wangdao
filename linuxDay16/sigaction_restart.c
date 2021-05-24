#include <func.h>

void sigFunc(int signum,siginfo_t *pInfo,void* p)
{
    printf("before sleep %d is comming\n",signum);
    sleep(3);//模拟信号处理函数里做一些工作
    printf("after sleep %d is comming\n",signum);
}

int main()
{
    struct sigaction act;
    bzero(&act,sizeof(act));

    //相当于信号的捕捉和处理是一次性的
    act.sa_flags = SA_SIGINFO|SA_RESTART;
    /* act.sa_flags = SA_SIGINFO; */
    act.sa_sigaction = sigFunc;
    int ret;


    ret = sigaction(SIGINT,&act,NULL);
    ERROR_CHECK(ret,-1,"sigaction");

    //让进程去读标准输入，这样没有标准输入的时候，进程就会阻塞在read()处
    char buf[64]={0};
    ret = read(0,buf,sizeof(buf));
    printf("ret=%d,buf=%s\n",ret,buf);

    return 0;
}

