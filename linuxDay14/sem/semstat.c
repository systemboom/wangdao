#include <func.h>

int main()
{
    int semArrId = semget(1000,1,IPC_CREAT|0600); 
    ERROR_CHECK(semArrId,-1,"semget");

    struct semid_ds stat;
    memset(&stat,0,sizeof(stat));
    //stat初始化，清零
    int ret;
    ret = semctl(semArrId,0,IPC_STAT,&stat);
    //将状态传入stat
    ERROR_CHECK(ret,-1,"semctl");

    printf("sem_nsems=%ld,perm=%o\n",stat.sem_nsems,stat.sem_perm.mode);

    return 0; 
}

