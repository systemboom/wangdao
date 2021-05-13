#include <func.h>

void *threadFunc(void *p)
{
    printf("child thread val=%s\n",(char*)p);
    return NULL;
}

int main()
{
    pthread_t thid;

    char *p = (char*)malloc(20);
    strcpy(p,"hello");

    int ret;
    ret = pthread_create(&thid,NULL,threadFunc,p);
    THREAD_ERRORCHECK(ret,"pthread_create");
    
    printf("ret=%d\n",ret);
    printf("main thread after create\n");
    pthread_join(thid,NULL);
}

