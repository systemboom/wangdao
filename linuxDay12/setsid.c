#include <func.h>

int main()
{
    printf("sid = %d\n",getsid(0));
    int ret=setsid();
    ERROR_CHECK(ret,-1,"setsid");
    printf("sid = %d\n",getsid(0));
    while(1);
    return 0;
}
