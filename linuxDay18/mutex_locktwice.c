#include <func.h>

int main()
{
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,NULL);//创建锁，锁的属性暂时设置NULL
    pthread_mutex_lock(&mutex);//加锁
    printf("lock success\n");
    //第一次加锁成功之后，锁是锁住的状态
    //此时再去加锁，就会阻塞
    pthread_mutex_lock(&mutex);//第二次加锁，阻塞
    printf("you can not see me\n");

    pthread_mutex_unlock(&mutex);//解锁
    pthread_mutex_destroy(&mutex);//注销互斥锁
}

