#include <func.h>

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}Data_t,*pData_t;

void* threadFunc(void* p)
{
    pData_t pData = (pData_t)p;
    struct timespec t;
    t.tv_sec = time(NULL)+3;
    //time(null)获取当前绝对时间，+3秒表示计时3秒
    printf("child alive\n");
    pthread_mutex_lock(&pData->mutex);
    printf("child lock success\n");
    pthread_cond_timedwait(&pData->cond,&pData->mutex,&t);
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
    /* sleep(1);//表示放票的一个时间间隔 */
    //假如有人退票，就把正在wait的线程唤醒
    printf("tickets ready : signal\n");
    /* pthread_cond_signal(&data.cond); */

    pthread_join(thid,NULL);
}

