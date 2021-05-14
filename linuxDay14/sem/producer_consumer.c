#include <func.h>

int main()
{

    int semArrId = semget(1000,2,IPC_CREAT|0600);
    //创建2个信号量，分别标识仓库和产品的数量
    ERROR_CHECK(semArrId,-1,"semget");

    //集合里第1个信号量表示仓库数量，下标为0
    //第2个信号量表示产品的数量，下标为1

    //设定信号量初值分别为10,0
    unsigned short arr[2]={10,0};
    int ret;
    ret = semctl(semArrId,0,SETALL,arr);
    ERROR_CHECK(ret,-1,"semctl");

    struct sembuf sopp,sopv;
    //定义sops结构体
    if(fork())
    {
        while(1)
        {//生产者
            //父进程生产产品，对产品做v操作，消耗仓库，对仓库做p操作
            sopp.sem_num=0;//信号量编号，下标0的是仓库，P
            sopp.sem_op=-1;//一次操作改变的数值
            sopp.sem_flg = SEM_UNDO;
            sopv.sem_num=1;//下标1的是产品，V
            sopv.sem_op=1;
            sopv.sem_flg=SEM_UNDO;
            //SEM_UNDO将使操作系统跟踪当前进程对这个信号量的修改情况，如果这个进程在没有释放该信号量的情况下终止，
            //操作系统将自动释放该进程持有的信号量。
            printf("producer1 repo=%d,product=%d\n",semctl(semArrId,0,GETVAL),semctl(semArrId,1,GETVAL));
            
            semop(semArrId,&sopp,1);//占用了一个仓库，对仓库做p操作，减1
            printf("producer2 repo=%d,product=%d\n",semctl(semArrId,0,GETVAL),semctl(semArrId,1,GETVAL));
            
            semop(semArrId,&sopv,1);//生产了一个产品，对产品做v操作，加1
            printf("producer3 repo=%d,product=%d\n",semctl(semArrId,0,GETVAL),semctl(semArrId,1,GETVAL));
            sleep(1);
        }

    }
    else{
        while(1)
        {//消费者
            //子进程消耗产品，对产品做P操作，释放仓库，对仓库做v操作
            sopp.sem_num=1;///信号量编号，下标1的是产品，P
            sopp.sem_op=-1;
            sopp.sem_flg=SEM_UNDO;
            sopv.sem_num=0;//下标0的是仓库，V
            sopv.sem_op=1;
            sopv.sem_flg=SEM_UNDO;

            printf("consumer1 repo=%d,product=%d\n",semctl(semArrId,0,GETVAL),semctl(semArrId,1,GETVAL));
            
            semop(semArrId,&sopp,1);//消耗了一个产品
            printf("consumer2 repo=%d,product=%d\n",semctl(semArrId,0,GETVAL),semctl(semArrId,1,GETVAL));
            
            semop(semArrId,&sopv,1);//释放了一个仓库
            printf("consumer3 repo=%d,product=%d\n",semctl(semArrId,0,GETVAL),semctl(semArrId,1,GETVAL));
            sleep(2);
        }
    }
}
