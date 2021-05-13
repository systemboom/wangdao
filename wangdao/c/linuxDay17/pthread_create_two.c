#include <func.h>

void *threadFunc(void *p)
{
    printf("child thread create val=%ld\n",(long)p);
    return NULL;
}

int main()
{
    pthread_t thid,thid1;

    /* int iStack=3; */
    long iStack=3;

    int ret;
    ret = pthread_create(&thid,NULL,threadFunc,(void*)iStack);
    //(void*)iStack是值传递，指针是8个字节，long也是8个字节
    THREAD_ERRORCHECK(ret,"pthread_create");

    iStack = 6;
    ret = pthread_create(&thid1,NULL,threadFunc,(void*)iStack);
    THREAD_ERRORCHECK(ret,"pthread_create");
    
    printf("main thread after create\n");
    pthread_join(thid,NULL);
}

