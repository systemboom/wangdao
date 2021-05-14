#include <func.h>

void *threadFunc(void *p)
{
    printf("child thread create val=%d\n",*(int *)p);
    /* pthread_exit(3); */
    long tRet =3;
    pthread_exit((void*)tRet);
}

int main()
{
    pthread_t thid;

    int iStack=3;

    int ret;
    ret = pthread_create(&thid,NULL,threadFunc,&iStack);
    THREAD_ERRORCHECK(ret,"pthread_create");
    
    long threadRetVal;
    
    ret = pthread_join(thid,(void**)&threadRetVal);
    //pthread_join()的第二个参数是一个void**类型，所以这里要做一个强转
    //因为long和指针同为8个字节，取地址传进来是一级指针，用(void**)
    //强转成二级指针。用(void**)&threadRetVal接收(void*)tRet，pthread_join函数
    //内部会对(void**)&threadRetVal做解引用
    THREAD_ERRORCHECK(ret,"pthread_join");

    printf("main thread join end child ret=%ld\n",threadRetVal);
    //打印子线程的返回值threadRetVal
}
