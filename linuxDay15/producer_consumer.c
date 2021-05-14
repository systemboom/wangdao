#include <func.h>

int main()
{

    int semArrId = semget(1000,2,IPC_CREAT|0600);
    ERROR_CHECK(semArrId,-1,"semget");

    //集合里第一个信号量表示仓库数量
    //第二个信号量表示产品的数量
    unsigned short arr[2]={10,0};
    int ret;
    ret = semctl(semArrId,0,SETALL,arr);
    ERROR_CHECK(ret,-1,"semctl");

    struct sembuf buf[2];
    if(fork())
    {
        while(1)
        {
            //父进程生产产品，消耗仓库
            buf[0].sem_num=0;
            buf[0].sem_op=-1;
            buf[0].sem_flg = SEM_UNDO;
            buf[1].sem_num=1;
            buf[1].sem_op=1;
            buf[1].sem_flg=SEM_UNDO;

            printf("producer1 repo=%d,product=%d\n",semctl(semArrId,0,GETVAL),semctl(semArrId,1,GETVAL));
            //占用了一个仓库,并且生产了一个产品
            //PV操作一次完成,对两个不同的信号量分别P，V
            semop(semArrId,buf,2);
            printf("producer2 repo=%d,product=%d\n",semctl(semArrId,0,GETVAL),semctl(semArrId,1,GETVAL));
            sleep(1);
        }
    }
    else{
        while(1)
        {
            //子进程消耗产品，释放仓库
            buf[0].sem_num=1;
            buf[0].sem_op=-1;
            buf[0].sem_flg=SEM_UNDO;
            buf[1].sem_num=0;
            buf[1].sem_op=1;
            buf[1].sem_flg=SEM_UNDO;

            printf("consumer1 repo=%d,product=%d\n",semctl(semArrId,0,GETVAL),semctl(semArrId,1,GETVAL));
            //消耗了一个产品,同时释放了一个仓库
            semop(semArrId,buf,2);
            printf("consumer2 repo=%d,product=%d\n",semctl(semArrId,0,GETVAL),semctl(semArrId,1,GETVAL));
            sleep(2);
        }
    }
}
