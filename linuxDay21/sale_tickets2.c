#include <func.h>

typedef struct {
    /* int exitflag; */
    int repo;
    int product;
    int tickets;//代表资源数目
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}Data_t,*pData_t;

//消费者的消费能力比较强
//此时如果没有票，消费者需要等待
//当生产者生产了余票之后
//通知消费者继续卖票
void* saleWindow1(void* p)
{
    pData_t pData = (pData_t)p;
    while(1)
    {
        /* printf("saleWindow1\n"); */
        pthread_mutex_lock(&pData->mutex);
        /* printf("saleWindow1 sale tickets %d\n",pData->tickets); */
        if(pData->tickets == 0 )
        {
            printf("sale Window wait\n");
            /* printf("saleWindow1 sale tickets %d\n",pData->tickets); */
            pthread_cond_wait(&pData->cond,&pData->mutex);
            //两个线程被broadcast唤醒后，会去抢锁
            //但是只有一个线程能抢到，另一个线程就会卡在pthread_mutex_lock上面
            //假设1号线程抢到锁，2号线程已经醒来，但是加锁不成功
            //就阻塞在加锁上面
            //当1号线程加锁之后，接下来的一段时间可能锁都会分配给1号线程
            //在这段时间内1号线程卖完了票，又回到了pthread_cond_wait
            //1号线程解锁之后睡眠，等待被cond_broadcast唤醒
            //此时2号线程终于能够加锁成功，从cond_wait返回
            // 从cond_wait返回后执行下面的tickets--，然后票就变成负数了
        }
        if(pData->tickets>0)
            pData->tickets--;
       		/* printf("saleWindow1 sale tickets %d\n",pData->tickets); */
        	pthread_mutex_unlock(&pData->mutex);
    }

    pthread_exit(NULL);
}

void* saleWindow2(void* p)
{
    pData_t pData = (pData_t)p;
    while(1)
    {
        printf("saleWindow2\n");
        pthread_mutex_lock(&pData->mutex);
        printf("saleWindow2 sale tickets %d\n",pData->tickets);
        if(pData->tickets == 0 )
        {
            /* printf("saleWindow2 sale tickets %d\n",pData->tickets); */
            printf("sale Window wait\n");
            pthread_cond_wait(&pData->cond,&pData->mutex);
        }
        /* sleep(1); */
        if(pData->tickets>0)
            pData->tickets--;
        /* printf("saleWindow2 sale tickets %d\n",pData->tickets); */
        pthread_mutex_unlock(&pData->mutex);

    }

    pthread_exit(NULL);
}

void* setTickets(void* p)
{
    pData_t pData = (pData_t)p;
    while(1)
    {
        
        /* printf("setTickets\n"); */
        pthread_mutex_lock(&pData->mutex);
        /* printf("setTickets %d\n",pData->tickets); */
        if(pData->tickets == 0)
        {
            pData->tickets = 20;
            printf("set ticet 20\n");
            pthread_cond_broadcast(&pData->cond);
        }
        pthread_mutex_unlock(&pData->mutex);
        /* usleep(1000); */
        /* sleep(2); */
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t thid1;
    pthread_t thid2;
    pthread_t thid3;
    Data_t data;
    pthread_mutex_init(&data.mutex,NULL);
    pthread_cond_init(&data.cond,NULL);
    data.tickets=10;

    pthread_create(&thid1,NULL,saleWindow1,&data);
    pthread_create(&thid2,NULL,saleWindow2,&data);
    pthread_create(&thid3,NULL,setTickets,&data);

    pthread_join(thid1,NULL);
    pthread_join(thid2,NULL);
    pthread_join(thid3,NULL);
}

