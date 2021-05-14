#include <func.h>

int main()
{
    pthread_mutex_t mutex;
    //锁初始化之后是未锁定的状态
    pthread_mutex_init(&mutex,NULL);
    pthread_mutex_lock(&mutex);
    printf("lock success\n");
    //第一次加锁成功之后，锁是锁住的状态
    //此时再去加锁，就会阻塞
    //如果此时使用的是trylock,线程就不会阻塞
    int ret ;
    ret = pthread_mutex_trylock(&mutex);
    THREAD_ERRORCHECK(ret,"pthread_mutex_trylock");
    printf("trylock ret = %d\n",ret);

    pthread_mutex_unlock(&mutex);
    pthread_mutex_destroy(&mutex);
}

