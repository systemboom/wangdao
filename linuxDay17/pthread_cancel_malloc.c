#include <func.h>

void *threadFunc(void *p)
{
    char *pStr =(char*)malloc(20);
    strcpy(pStr,"hello");
    printf("pstr = %s\n",pStr);
    free(pStr);
    //free没有得到执行，代表资源没有被释放
    //因为printf是取消点函数，执行完printf线程就被取消了
    printf("ready to return\n");
    pStr = NULL;//避免野指针
    return NULL;
}

int main()
{
    pthread_t thid;
    int ret;
    ret = pthread_create(&thid,NULL,threadFunc,NULL);
    THREAD_ERRORCHECK(ret,"pthread_create");


    ret = pthread_cancel(thid);
    THREAD_ERRORCHECK(ret,"pthread_cancel");

    //如果子线是被cancel掉的，通过pthread_join得到的threadRet是-1
    long threadRet;
    pthread_join(thid,(void**)&threadRet);
    printf("after join threadRet=%ld\n",threadRet);
    return 0;
}

