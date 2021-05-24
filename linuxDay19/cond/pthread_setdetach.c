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
    while(1);
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

    pthread_attr_t attr;
    pthread_attr_init(&attr);//初始化属性结构体
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    //设置属性为PTHREAD_CREATE_DETACHED，该线程运行结束后会自动释
    //放所有资源，我们不能等待它们终止

    //第一次加锁成功之后，锁是锁住的状态
    //此时再去加锁，就会阻塞
    pthread_create(&thid,&attr,threadFunc,&data);
    /* sleep(1);//表示放票的一个时间间隔 */
    //假如有人退票，就把正在wait的线程唤醒
    printf("tickets ready : signal\n");
    pthread_cond_signal(&data.cond);

    int ret = pthread_join(thid,NULL);
    THREAD_ERRORCHECK(ret,"pthread_join");
    
}
