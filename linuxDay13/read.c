#include <func.h>

int main()
{
    char buf[64]={0};
    read(0,buf,sizeof(buf));
    printf("i am read\n");
    printf("buf=%s\n",buf);
    return 0;
 
}

