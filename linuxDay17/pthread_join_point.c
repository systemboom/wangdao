#include <func.h>

void *threadFunc(void *p)
{
    printf("child thread create val=%d\n",*(int *)p);
    /* pthread_exit(3); */
    char *p1=(char*)malloc(20);
    strcpy(p1,"succes");

    pthread_exit(p1);
    //void*和char*是可以互相转换的
}

int main()
{
    pthread_t thid;

    int iStack=3;

    int ret;
    ret = pthread_create(&thid,NULL,threadFunc,&iStack);
    THREAD_ERRORCHECK(ret,"pthread_create");
    
    char* threadRet; 
    
    ret = pthread_join(thid,(void**)&threadRet);
    //threadRet是一级指针，取地址之后是二级指针，再强转成（void**）
    THREAD_ERRORCHECK(ret,"pthread_join");

    printf("child ret buf=%s\n",threadRet);
}
