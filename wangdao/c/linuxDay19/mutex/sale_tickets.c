#include <func.h>

#define N 20
typedef struct {
    int tickets;
    pthread_mutex_t mutex;
}Data_t,*pData_t;

void* threadFunc1(void* p)
{
    int num=0;
    pData_t pData = (pData_t)p;
    while(1)
    {
        pthread_mutex_lock(&pData->mutex);
        if(pData->tickets>0)
        {
            /* printf("window1 start tickets=%d\n",pData->tickets); */
            pData->tickets--;
            num++;
            /* printf("window1 sale tickets=%d\n",pData->tickets); */
            pthread_mutex_unlock(&pData->mutex);
        }
        else{
            pthread_mutex_unlock(&pData->mutex);
            printf("window1 sale end total=%d\n",num);
            break;
        }
        
    }
    pthread_exit(NULL);
}

void* threadFunc2(void* p)
{
    int num=0;
    pData_t pData = (pData_t)p;
    while(1)
    {
        pthread_mutex_lock(&pData->mutex);
        if(pData->tickets>0)
        {
            /* printf("window2 start tickets=%d\n",pData->tickets); */
            pData->tickets--;
            num++;
            /* printf("window2 sale tickets=%d\n",pData->tickets); */
            pthread_mutex_unlock(&pData->mutex);
        }
        else{
            pthread_mutex_unlock(&pData->mutex);
            printf("window2 sale end total=%d\n",num);
            break;
        }
        
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t thid1;
    pthread_t thid2;

    Data_t data;
    data.tickets=60000000;
    pthread_mutex_init(&data.mutex,NULL);

    pthread_create(&thid1,NULL,threadFunc1,&data);
    pthread_create(&thid2,NULL,threadFunc2,&data);
    pthread_join(thid1,NULL);
    pthread_join(thid2,NULL);
}
