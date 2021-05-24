#include <func.h>

int main()
{
    int shmid= shmget(1000,1<<20,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmid");

    int *p = (int*)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(int*)-1,"shmat");
    p[0]=10;

    struct shmid_ds stat;
    memset(&stat,0,sizeof(stat));

    int ret = shmctl(shmid,IPC_STAT,&stat);
    ERROR_CHECK(ret,-1,"shmctl");
    printf("shm size=%ld,attch num=%ld\n",stat.shm_segsz,
           stat.shm_nattch);
    printf("shm mode=%o\n",stat.shm_perm.mode);

    //修改权限
    stat.shm_perm.mode = 0666;

    ret = shmctl(shmid,IPC_SET,&stat);
    ERROR_CHECK(ret,-1,"shmctl");
    printf("shm mode=%o\n",stat.shm_perm.mode);
    while(1);
    return 0;
}
