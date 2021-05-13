#include <func.h>

void* threadFunc(void* p)
{
    pthread_mutex_t* pMutex = (pthread_mutex_t*)p;
    printf("child alive\n");
    // 调用unlock是可以解开其他线程lock的锁的
    pthread_mutex_unlock(pMutex);
    printf("child lock success\n");

    pthread_exit(NULL);
}

int main()
{
    pthread_t thid;
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,NULL);

    //第一次加锁成功之后，锁是锁住的状态
    //此时再去加锁，就会阻塞
    pthread_create(&thid,NULL,threadFunc,&mutex);
    pthread_mutex_lock(&mutex);
    printf("main lock success\n");
    sleep(1);
    pthread_join(thid,NULL);
    pthread_mutex_destroy(&mutex);
}

