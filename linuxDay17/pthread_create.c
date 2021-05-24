#include <func.h>

void *threadFunc(void *p)
{
    printf("child thread create\n");
    return NULL;
}

int main()
{
    pthread_t thid;
    int ret;
    ret = pthread_create(&thid,NULL,threadFunc,NULL);
    THREAD_ERRORCHECK(ret,"pthread_create");
    
    printf("ret=%d\n",ret);
    printf("main thread after create\n");
    usleep(100);
    /* return 0; */ 
    exit(0); 
    _exit(0);
}

