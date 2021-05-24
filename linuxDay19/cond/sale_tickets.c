#include <func.h>
#define N 20
typedef struct {
    int tickets;
    pthread_mutex_t mutex;
    pthread_cond_t cond; // 代表有票的条件是否成立
}Data_t,*pData_t;

void* threadFunc1(void* p)
{
    pData_t pData = (pData_t)p;
    while(1)
    {
        pthread_mutex_lock(&pData->mutex);
        if(pData->tickets == 0)
        {//没票了
            printf("sale window1 tieckets is %d ,wait\n",pData->tickets);
            /* pthread_cond_wait(&pData->cond1,&pData->mutex); */
            pthread_cond_signal(&pData->cond);
            //告诉放票窗口，需要放票了

            pthread_mutex_unlock(&pData->mutex);
        }
        else{
        //买票
            printf("sale window 1 wake up\n");
            printf("window1 start tickets=%d\n",pData->tickets);
            pData->tickets--;
            pthread_mutex_unlock(&pData->mutex);
        }
        /* sleep(1); */ 

    }
    pthread_exit(NULL);
}

void* threadFunc2(void* p)
{
    pData_t pData = (pData_t)p;
    while(1)
    {
        pthread_mutex_lock(&pData->mutex);
        if(pData->tickets == 0)
        {//没票了
            printf("sale window2 tieckets is %d ,wait\n",pData->tickets);
            pthread_cond_signal(&pData->cond);
             //告诉放票窗口，需要放票了

            pthread_mutex_unlock(&pData->mutex);
            /* pthread_cond_wait(&pData->cond1,&pData->mutex); */
           
        }
        else{
        //买票
            printf("sale window 2 wake up\n");
            printf("window2 start tickets=%d\n",pData->tickets);
            pData->tickets--;
            /* num++; */
            /* printf("window1 sale tickets=%d\n",pData->tickets); */
            pthread_mutex_unlock(&pData->mutex);
        }

    }
    pthread_exit(NULL);
}

void* setTickets(void*p)
{
    pData_t pData = (pData_t)p;
    while(1)
    {
        pthread_mutex_lock(&pData->mutex);
        if(pData->tickets>0)
        {
            printf(" before set ticket\n");
            pthread_cond_wait(&pData->cond,&pData->mutex);
            pData->tickets = 20;//每次放20张票
            /* pData->tickets = 20000000; */
            printf("setTickets wake up, tickets=%d\n",pData->tickets);
            /* pthread_cond_signal(&pData->cond1); */
            pthread_mutex_unlock(&pData->mutex);
        }
    }
}

int main()
{
    pthread_t thid1;
    pthread_t thid2;
    pthread_t thid3;

    Data_t data;
    data.tickets=20;
    pthread_mutex_init(&data.mutex,NULL);
    pthread_cond_init(&data.cond,NULL);

    pthread_create(&thid1,NULL,threadFunc1,&data);
    pthread_create(&thid2,NULL,threadFunc2,&data);

    pthread_create(&thid3,NULL,setTickets,&data);
    pthread_join(thid1,NULL);
    pthread_join(thid2,NULL);
    pthread_join(thid3,NULL);

}

