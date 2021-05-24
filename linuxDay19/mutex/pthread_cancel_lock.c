#include <func.h>

#define N 30000000
typedef struct data{
    int val;
    pthread_mutex_t mutex;
}Data_t,*pData_t;

void cleanupFunc(void* p)
{
    pthread_mutex_t* pMutex = (pthread_mutex_t*)p;
    printf("clean up Func\n");
    pthread_mutex_unlock(pMutex);
}

void* threadFunc(void* p)
{
    /* pData_t pData = (pData_t)p; */
    pthread_mutex_t *pMutex = (pthread_mutex_t*)p;
    pthread_cleanup_push(cleanupFunc,pMutex);
    pthread_mutex_lock(pMutex);
    sleep(1);//模拟子线程工作的过程
    pthread_mutex_unlock(pMutex);

    pthread_exit(NULL);
    pthread_cleanup_pop(1);
}

int main()
{
    pthread_t thid1;
    pthread_t thid2;

    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,NULL);//初始化锁

    //创建两个子线程
    pthread_create(&thid1,NULL,threadFunc,&mutex);
    pthread_create(&thid2,NULL,threadFunc,&mutex);

    pthread_cancel(thid1);
    pthread_cancel(thid2);

    long threadRet = 0;
    pthread_join(thid1,(void**)&threadRet);
    printf("thread1 Ret=%ld\n",threadRet);
    pthread_join(thid2,(void**)&threadRet);
    printf("thread2 Ret=%ld\n",threadRet);

}

