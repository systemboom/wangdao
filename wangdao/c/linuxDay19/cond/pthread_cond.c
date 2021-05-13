#include <func.h>

//定义结构体，把锁和条件变量都包含进来
typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}Data_t,*pData_t;

void* threadFunc(void* p)
{
    pData_t pData = (pData_t)p;

    printf("child alive\n");//子线程运行

    pthread_mutex_lock(&pData->mutex);//子线程加锁
    printf("child lock success\n");

    pthread_cond_wait(&pData->cond,&pData->mutex);//条件成立，唤醒子线程
    printf("child awake\n");
    
    pthread_mutex_unlock(&pData->mutex);//子线程解锁

    pthread_exit(NULL);
}

int main()
{
    pthread_t thid;
    Data_t data;
    pthread_mutex_init(&data.mutex,NULL);//创建锁
    pthread_cond_init(&data.cond,NULL);//创建条件变量

    //第一次加锁成功之后，锁是锁住的状态
    //此时再去加锁，就会阻塞
    pthread_create(&thid,NULL,threadFunc,&data);
    sleep(1);//表示放票的一个时间间隔
    
    //假如有人退票，就把正在wait的线程唤醒
    printf("tickets ready : signal\n");
    pthread_cond_signal(&data.cond);//唤醒等待该条件的线程

    pthread_join(thid,NULL);
}

