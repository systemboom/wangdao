#include <func.h>

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}Data_t,*pData_t;

void cleanupFunc(void* p)
{
    pData_t pData = (pData_t)p;
    printf("unlock\n");
    pthread_mutex_unlock(&pData->mutex);
}

void* threadFunc(void* p)
{
    sleep(1);
    pData_t pData = (pData_t)p;
    /* pthread_cleanup_push(cleanupFunc,pData); */
    printf("child alive\n");
    pthread_mutex_lock(&pData->mutex);
    printf("child lock success\n");
    pthread_cond_wait(&pData->cond,&pData->mutex);
    printf("child awake\n");
    /* pthread_mutex_unlock(&pData->mutex); */
    //从条件变量上被唤醒之后可以去访问资源

    /* pthread_cleanup_pop(1); */
    pthread_exit(NULL);
}

int main()
{
    pthread_t thid1;
    pthread_t thid2;
    Data_t data;
    pthread_mutex_init(&data.mutex,NULL);
    pthread_cond_init(&data.cond,NULL);

    //第一次加锁成功之后，锁是锁住的状态
    //此时再去加锁，就会阻塞
    pthread_create(&thid1,NULL,threadFunc,&data);
    pthread_create(&thid2,NULL,threadFunc,&data);
    /* sleep(1);//表示放票的一个时间间隔 */
    //假如有人退票，就把正在wait的线程唤醒
    /* pthread_cancel(thid1); */
    /* pthread_cancel(thid2); */
    printf("tickets ready : broadcast\n");
    pthread_cond_broadcast(&data.cond);
    /* pthread_cond_signal(&data.cond); */
    /* pthread_cond_signal(&data.cond); */

    pthread_join(thid1,NULL);
    pthread_join(thid2,NULL);
}

