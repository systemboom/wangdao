#include <func.h>

void sigFunc(int signum)
{
    printf("sig %d is comming\n",signum);
}

int main()
{
    if(signal(SIGINT,sigFunc) == SIG_ERR)
    {
        printf("signal failed\n");
        return -1;
    }
    signal(SIGINT,sigFunc);
    sleep(10);
    printf("after sleep\n");
    signal(SIGINT,SIG_DFL);
    printf("after default\n");
    while(1);
    return 0;
}

