#include <func.h>

int main()
{
    int shmid= shmget(1000,1<<20,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmid");

    int *p = (int*)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(int*)-1,"shmat");
    printf("shm data=%d\n",p[0]);
    return 0;
}
