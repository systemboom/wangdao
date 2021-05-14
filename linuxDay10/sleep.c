#include <func.h>

int main()
{
    char buf[20]={0};
    read(0,buf,sizeof(buf));
    sleep(50);
    return 0;
}

