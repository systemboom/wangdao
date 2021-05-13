#include <func.h>

typedef struct {
    int tickets;//代表资源数目
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}Data_t,*pData_t;

void* saleWindow1(void* p)
{
    pData_t pData = (pData_t)p;
    while(1)
    {
        pthread_mutex_lock(&pData->mutex);
        //先加锁，再判断票数

        if(pData->tickets > 0 )
        {
            printf("saleWindow1 sale tickets %d\n",pData->tickets);
            pData->tickets--;
            //票数为0时，通知放票窗口放票
            if(pData->tickets == 0)
            {
                pthread_cond_signal(&pData->cond);
            }
        }

        pthread_mutex_unlock(&pData->mutex);//解锁
    }

    pthread_exit(NULL);
}

void* saleWindow2(void* p)
{
    pData_t pData = (pData_t)p;
    while(1)
    {
        pthread_mutex_lock(&pData->mutex);
        //先加锁，再判断票数

        
        //票数为0时，通知放票窗口放票
        if(pData->tickets > 0 )
        {
            printf("saleWindow2 sale tickets %d\n",pData->tickets);
            pData->tickets--;
            if(pData->tickets == 0)
            {
                pthread_cond_signal(&pData->cond);
            }
        }

        pthread_mutex_unlock(&pData->mutex);//解锁

    }

    pthread_exit(NULL);
}

void* setTickets(void* p)
{
    pData_t pData = (pData_t)p;
    while(1)
    {
        
        pthread_mutex_lock(&pData->mutex);
        //先加锁，再判断票数

        if(pData->tickets > 0)
        {//如果票池中还有余票，窗口就等待,直到被卖票线程唤醒

            printf("setTickets thread wait\n");
            pthread_cond_wait(&pData->cond,&pData->mutex);
        }
        pData->tickets = 20;
        printf("set ticet 20\n");
        pthread_mutex_unlock(&pData->mutex);//解锁

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

