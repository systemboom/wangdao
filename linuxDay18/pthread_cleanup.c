#include <func.h>

void cleanFunc(void *p)
{
    printf("i am cleanFunc\n");
}

void cleanupFunc2(void*p)
{
    printf("i am 2 cleanupFunc\n");
}

void *threadFunc(void *p)
{
    char *pStr =(char*)malloc(20);
    //注册线程清理函数，当线程终止的时候，就会执行清理函数
    //帮我们把需要释放的资源释放掉 
    pthread_cleanup_push(cleanFunc,pStr);
    pthread_cleanup_push(cleanupFunc2,pStr);
    strcpy(pStr,"hello");
    char buf[64]={0};
    int ret = read(0,buf,sizeof(buf));
    printf("ret=%d,buf=%s\n",ret,buf);
    pthread_exit(NULL);
    //我们写了pop(1),只是为了大括号的匹配
    pthread_cleanup_pop(1);
    pthread_cleanup_pop(1);
    //每有一个push，就要有一个pop
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

