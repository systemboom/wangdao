#include <func.h>

void func()
{
    printf("this is func\n");
    pthread_exit(NULL);
    /* exit(0); */ //表示进程的退出,进程内的所有线程都会结束
    /* return ; */
}

void *threadFunc(void *p)
{
    printf("child thread create val=%d\n",*(int *)p);
    func();
    printf("after func\n");

    return NULL;
}

int main()
{
    pthread_t thid;

    int iStack=3;

    int ret;
    ret = pthread_create(&thid,NULL,threadFunc,&iStack);
    THREAD_ERRORCHECK(ret,"pthread_create");
    
    pthread_join(thid,NULL);
    printf("main thread join end\n");
}
