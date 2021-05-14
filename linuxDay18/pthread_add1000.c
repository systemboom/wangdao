#include <func.h>

#define N 30000000

typedef struct data{
    int val;
    pthread_mutex_t mutex;
}Data_t,*pData_t;

void* threadFunc(void* p)
{
    pData_t pData = (pData_t)p;//void*转换成pData_t
    for(int i=0;i<N;i++)
    {
        pthread_mutex_lock(&pData->mutex);
        pData->val +=1;//表示对共享资源的访问
        pthread_mutex_unlock(&pData->mutex);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t thid;

    Data_t data;
    data.val=0;
    pthread_mutex_init(&data.mutex,NULL);
    struct timeval start,end;

    gettimeofday(&start,NULL);
    //第一次加锁成功之后，锁是锁住的状态
    //此时再去加锁，就会阻塞
    pthread_create(&thid,NULL,threadFunc,&data);
    /* pthread_mutex_lock(&mutex); */
    /* printf("main lock success\n"); */

    for(int i=0;i<N;i++)
    {
        pthread_mutex_lock(&data.mutex); 
        data.val +=1;//表示对共享资源的访问
        pthread_mutex_unlock(&data.mutex);
    }

    pthread_join(thid,NULL);
    gettimeofday(&end,NULL);
    printf("val=%d,cost time= %ld\n",data.val,
           (end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec));
}

