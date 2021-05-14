#include <func.h>

int main()
{
    //锁的属性的初始化和设置
    pthread_mutexattr_t mutexattr; 
    pthread_mutexattr_init(&mutexattr);
    //PTHREAD_MUTEX_RECURSIVE表示嵌套锁
    //允许同一个线程对同一把锁加锁多次
    pthread_mutexattr_settype(&mutexattr,PTHREAD_MUTEX_RECURSIVE);

    //锁的初始化
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,&mutexattr);

    //多次加锁
    pthread_mutex_lock(&mutex);
    printf("lock success\n");
    pthread_mutex_lock(&mutex);
    printf("lock success\n");
    pthread_mutex_lock(&mutex);
    printf("lock success\n");

    //依次解锁
    pthread_mutex_unlock(&mutex);
    pthread_mutex_unlock(&mutex);
    pthread_mutex_unlock(&mutex);
    pthread_mutex_destroy(&mutex);
}

