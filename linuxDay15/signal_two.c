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
    signal(3,sigFunc);
    while(1);
    return 0;
}
