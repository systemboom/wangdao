#include <func.h>

int main()
{
    int shmid= shmget(1000,1<<20,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmid");

    int *p = (int*)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(int*)-1,"shmat");
    p[0]=10;
    /* shmdt(p); */
    //共享内存的删除是标记删除
    //当最后一个使用共享内存的进程解除映射之后
    //才会被真正的删除
    int ret = shmctl(shmid,IPC_RMID,NULL);
    ERROR_CHECK(ret,-1,"shmctl");
    while(1);
    return 0;
}

