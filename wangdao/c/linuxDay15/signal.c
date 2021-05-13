#include <func.h>

void sigFunc(int signum)
{
    printf("sig %d is comming\n",signum);
}

int main()
{
    signal(SIGINT,sigFunc);
    while(1);
    return 0;
}

