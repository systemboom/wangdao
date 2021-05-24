#include <func.h>

int main()
{
    //收到2号信号会直接忽略，不去响应
    signal(SIGINT,SIG_IGN);
    while(1);
    return 0;
}

