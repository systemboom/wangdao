#include <func.h>

void cleanFunc(void *p)
{
    printf("i am cleanFunc\n");
    free(p);
    p=NULL; 
    printf("after free\n");
}

void *threadFunc(void *p)
{
    char *pStr =(char*)malloc(20);
    //注册线程清理函数，当线程终止的时候，就会执行清理函数
    //帮我们把需要释放的资源释放掉
    pthread_cleanup_push(cleanFunc,pStr);
    strcpy(pStr,"hello");
    printf("pstr = %s\n",pStr);
    //子线程执行完printf就cancel了，后面的程序都没运行，
    //但其后面会pop弹栈清理函数，运行清理函数cleanFunc用于清理资源
    free(p);
    printf("ready to return\n");
    return NULL;
    /* pthread_exit(NULL); */
    //我们写了pop(1),只是为了大括号的匹配
    pthread_cleanup_pop(1);
}

int main()
{
    pthread_t thid;
    int ret;
    ret = pthread_create(&thid,NULL,threadFunc,NULL);
    THREAD_ERRORCHECK(ret,"pthread_create");

    //如果子线程执行完printf之后，到while1了
    //再收到cancel信号，子线程就不会被取消
    /* sleep(1); */
    ret = pthread_cancel(thid);
    THREAD_ERRORCHECK(ret,"pthread_cancel");

    //如果子线是被cancel掉的，通过pthread_join得到的threadRet是-1
    long threadRet;
    pthread_join(thid,(void**)&threadRet);
    printf("after join threadRet=%ld\n",threadRet);
    return 0;
}

