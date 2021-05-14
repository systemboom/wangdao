#include <func.h>

void *threadFunc(void *p)
{
    //printf是cancel点，运行完之后子线程就会结束
    /* printf("child thread create\n"); */
    while(1);
    return NULL;
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
    ret = pthread_cancel(thid);//向thid线程发送cancel信号
    THREAD_ERRORCHECK(ret,"pthread_cancel");

    //如果子线是被cancel掉的，通过pthread_join得到的threadRet是-1
    long threadRet;
    pthread_join(thid,(void**)&threadRet);
    printf("after join threadRet=%ld\n",threadRet);
    return 0;
}
