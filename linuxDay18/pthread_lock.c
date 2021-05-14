#include <func.h>

void* threadFunc(void* p)
{
    pthread_mutex_t* pMutex = (pthread_mutex_t*)p;
    //主线程传过来的void*类型，需要转成pthread_mutex_t类型
    
    printf("child alive\n");
    pthread_mutex_lock(pMutex);//加锁
    printf("child lock success\n");
    pthread_mutex_unlock(pMutex);//解锁

    pthread_exit(NULL);//退出子线程
}

int main()
{
    pthread_t thid;
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,NULL);//初始化锁

    //第一次加锁成功之后，锁是锁住的状态
    //此时再去加锁，就会阻塞
    pthread_create(&thid,NULL,threadFunc,&mutex);
    //既然要子线程和主线程都要加锁，传给threadFunc的参数
    //自然是锁

    pthread_mutex_lock(&mutex);
    printf("main lock success\n");
    sleep(1);//表示这1s中内，锁在保护主线程使用的资源

    pthread_mutex_unlock(&mutex);
    pthread_join(thid,NULL);//等待子线程结束

    pthread_mutex_destroy(&mutex);
}
