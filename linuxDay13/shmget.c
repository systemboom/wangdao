
#include <func.h>

int main()
{
    int shmid= shmget(1000,1<<20,IPC_CREAT|0600);
    //大小是1的20次方，即1M,权限为0600
    ERROR_CHECK(shmid,-1,"shmid");
    printf("shmid=%d\n",shmid);
    return 0;
}

