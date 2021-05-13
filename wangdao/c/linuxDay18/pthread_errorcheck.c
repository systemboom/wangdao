#include <func.h>

int main()
{
    //锁的属性的初始化和设置
    pthread_mutexattr_t mutexattr; 
    pthread_mutexattr_init(&mutexattr);
    //PTHREAD_MUTEX_ERRORCHECK表示检错锁
    pthread_mutexattr_settype(&mutexattr,PTHREAD_MUTEX_ERRORCHECK);

    //锁的初始化 
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,&mutexattr);

    int ret ;
    ret = pthread_mutex_lock(&mutex);//第一次加锁
    printf("lock ret = %d\n",ret);
    ret = pthread_mutex_lock(&mutex);//第二次加锁
    printf("lock2 ret = %d\n",ret);
    THREAD_ERRORCHECK(ret,"lock");

    pthread_mutex_unlock(&mutex);
    pthread_mutex_destroy(&mutex);
}

