#include <func.h>


void sigFunc(int signum)
{
    time_t now;
    time(&now);
    printf("now time =%s\n",ctime(&now));
    
}

int main()
{

    signal(SIGPROF,sigFunc);

    sigFunc(3);
    struct itimerval tval;
    bzero(&tval,sizeof(tval));

    tval.it_value.tv_sec= 1;
    tval.it_interval.tv_sec = 3;

    int ret ;
    ret = setitimer(ITIMER_PROF,&tval,NULL);
    ERROR_CHECK(ret,-1,"setitimer");
    
    while(1);
}
