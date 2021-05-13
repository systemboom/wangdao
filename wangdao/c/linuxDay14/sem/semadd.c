#include <func.h>
#define N 10000000

int main()
{
    int shmid= shmget(1000,1<<20,IPC_CREAT|0600);
    //创建一大小为1M的共享内存段
    ERROR_CHECK(shmid,-1,"shmid");

    int semArrId = semget(2000,1,IPC_CREAT|0600);
    //创建一个信号量
    ERROR_CHECK(semArrId,-1,"semget");

    int ret;
    ret = semctl(semArrId,0,SETVAL,1);
    //将数组下标为0的信号量设值为1
    ERROR_CHECK(ret,-1,"semctl");

    int *p = (int*)shmat(shmid,NULL,0);
    //将共享内存映射到进程空间的某一地址
    ERROR_CHECK(p,(int*)-1,"shmat");
    p[0]=0;

    struct sembuf* buf = (struct sembuf*)malloc(2*sizeof(struct sembuf));


    //对sops数组初始化
    buf[0].sem_num=0;
    buf[0].sem_op=-1;
    buf[0].sem_flg=SEM_UNDO;
    buf[1].sem_num=0;
    buf[1].sem_op=1;
    buf[1].sem_flg=SEM_UNDO;
    /* struct sembuf sopp,sopv; */
    /* sopp.sem_num=0; */
    /* sopp.sem_op=-1; */
    /* sopp.sem_flg=SEM_UNDO; */
    /* sopv.sem_num=0; */
    /* sopv.sem_op=1; */
    /* sopv.sem_flg=SEM_UNDO; */

    if(fork())
    {
        for(int i=0;i<N;i++)
        {
            //加锁
            /* semop(semArrId,&sopp,1); */
            ret = semop(semArrId,&buf[0],1);
            //参数分别为 信号量集合 spos数组首地址 数组大小
            ERROR_CHECK(ret,-1,"semop");
            p[0]+=1;
            //解锁
            ret = semop(semArrId,&buf[1],1);
            ERROR_CHECK(ret,-1,"semop1");
            /* semop(semArrId,&sopv,1); */
        }
        wait(NULL);
        printf("total=%d\n",p[0]);
    }
    else{
        for(int i=0;i<N;i++)
        {
            //加锁
            ret = semop(semArrId,buf,1);
            ERROR_CHECK(ret,-1,"semop3");
            /* semop(semArrId,&sopp,1); */
            p[0]+=1;
            //解锁
            /* semop(semArrId,&sopv,1); */
            ret = semop(semArrId,&buf[1],1);
            ERROR_CHECK(ret,-1,"semop4");
        }
    }
    return 0;
}

