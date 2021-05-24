#include <func.h>

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}Data_t,*pData_t;

void* threadFunc(void* p)
{
    pData_t pData = (pData_t)p;
    printf("child alive\n");
    pthread_mutex_lock(&pData->mutex);
    printf("child lock success\n");
    pthread_cond_wait(&pData->cond,&pData->mutex);
    printf("child awake\n");
    pthread_mutex_unlock(&pData->mutex);

    pthread_exit(NULL);
}

int main()
{
    pthread_t thid;
    Data_t data;
    pthread_mutex_init(&data.mutex,NULL);
    pthread_cond_init(&data.cond,NULL);

    //第一次加锁成功之后，锁是锁住的状态
    //此时再去加锁，就会阻塞
    pthread_create(&thid,NULL,threadFunc,&data);
    printf("tickets ready : signal\n");
    pthread_cond_signal(&data.cond);

    pthread_join(thid,NULL);
}

