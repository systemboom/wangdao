#include <func.h>
#define N 10000000

int main()
{
    int shmid= shmget(1000,1<<20,IPC_CREAT|0600);
    ERROR_CHECK(shmid,-1,"shmid");

    int *p = (int*)shmat(shmid,NULL,0);
    //将共享内存映射到父进程的p
    ERROR_CHECK(p,(int*)-1,"shmat");
    p[0]=0;//将p的初始值设为0

    if(fork())
    {
        for(int i=0;i<N;i++)
        {
            p[0]+=1;
        }
        wait(NULL);
        printf("total=%d\n",p[0]);
    }
    {
        for(int i=0;i<N;i++)
        {
            p[0]+=1;
        }
    }
    return 0;
}
