#include "../include/thread_pool.h"

void *threadFunc(void* p)
{
    while(1);
}

int threadPoolInit(pThreadPool_t pPool,int threadNum,int capacity)
{
    bzero(pPool,sizeof(ThreadPool_t)); 
    queInit(&pPool->que,capacity);//初始化任务队列

    pthread_cond_init(&pPool->cond,NULL);//动态创建（初始化）条件变量，属性填NULL
    pPool->threadNum = threadNum;//线程数量
    pPool->startFlag = 0;//启动标志初始化
    pPool->pthid = (pthread_t*)calloc(threadNum,sizeof(pthread_t));//申请子线程空间
    return 0;
}

int threadPoolStart(pThreadPool_t pPool)//线程池启动/创建子线程
{

    if(0 == pPool->startFlag)
    {//判断线程池启动标志，创建完后会改成1
        for(int i=0;i<pPool->threadNum;i++)
        {//循环创建pPool->threadNum个子线程
            
            pthread_create(pPool->pthid+i,NULL,threadFunc,pPool);
            //创建线程，参数：子线程id,线程属性，线程函数，传给线程函数的地址的参数
            //pPool中存储线程池的数据结构，需要把pPool传给线程函数
            /* pthread_create(&pPool->pthid[i],NULL,threadFunc,pPool); */
        }
        pPool->startFlag = 1;
    }
    return 0;
}
