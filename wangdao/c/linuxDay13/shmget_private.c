#include <func.h>

int main()
{
    int shmid= shmget(IPC_PRIVATE,1<<20,IPC_CREAT|0600);
    /* int shmid= shmget(0,1<<20,IPC_CREAT|0600); */
    ERROR_CHECK(shmid,-1,"shmid");
    printf("shmid=%d\n",shmid);
    return 0;
}

