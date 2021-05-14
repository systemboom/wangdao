#include <func.h>

void* threadFunc(void* p)
{
    pthread_mutex_t pMutex = *(pthread_mutex_t*)p;
    //相当于复制了一把锁

    printf("child alive\n");
    pthread_mutex_lock(&pMutex);
    printf("child lock success\n");
    pthread_mutex_unlock(&pMutex);

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
    sleep(1);

    pthread_mutex_lock(&mutex);
    printf("main lock success\n");
    
    pthread_mutex_unlock(&mutex);
    printf("main unlock\n");
    
    pthread_join(thid,NULL);
    pthread_mutex_destroy(&mutex);
}

