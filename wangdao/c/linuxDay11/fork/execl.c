#include <func.h>

int main()
{
    int ret;
    printf("before execl\n");
    sleep(10);
    ret = execl("./print","myprint","1","3","5",NULL);
    printf("after execl\n");
    return 0;
}

