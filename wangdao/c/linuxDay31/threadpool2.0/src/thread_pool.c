#include "../include/thread_pool.h"

void *threadFunc(void* p)//线程函数（子线程）
{
    pThreadPool_t pPool = (pThreadPool_t)p;
    pNode_t pGet;//用于取任务节点的指针
    int getFlag=-1;
    //判断获取取任务节点是否成功的标志
    //-1表示不成功，0表示成功
    while(1)
    {
        if(0 == pPool->startFlag)
        {
            pthread_exit(0);
        }
        
        pthread_mutex_lock(&pPool->que.mutex);//加锁
       
       if(0 == pPool->que.queSize)//任务队列为空
        {
            printf("wait\n");
            pthread_cond_wait(&pPool->cond,&pPool->que.mutex);
            //任务队列为空，阻塞子线程，直到主线程中条件变量不为空时，
            //才被主线程中pthread_cond_signal唤醒

            printf("wake up\n");
        }
        //如果不为空，或者条件变量被唤醒
        getFlag = queGet(&pPool->que,&pGet);//获取任务队列中的任务节点

        pthread_mutex_unlock(&pPool->que.mutex);//已经获取完任务节点，可以解锁了

        if(0 == getFlag)
        {//获取文件成功

            transFile(pGet->clientFd);//传输文件
            
            close(pGet->clientFd);//关闭客户端
            free(pGet);//传输完文件，可以释放任务节点了
            pGet = NULL;//避免野指针，置空
        }
    }
}

int threadPoolInit(pThreadPool_t pPool,int threadNum,int capacity)
{
    bzero(pPool,sizeof(ThreadPool_t)); 
    queInit(&pPool->que,capacity);

    pthread_cond_init(&pPool->cond,NULL);
    pPool->threadNum = threadNum;
    pPool->startFlag = 0;
    pPool->pthid = (pthread_t*)calloc(threadNum,sizeof(pthread_t));
    return 0;
}

int threadPoolStart(pThreadPool_t pPool)
{

    if(0 == pPool->startFlag)
    {
        for(int i=0;i<pPool->threadNum;i++) 
        {
            pthread_create(pPool->pthid+i,NULL,threadFunc,pPool);
            /* pthread_create(&pPool->pthid[i],NULL,threadFunc,pPool); */
        }
        pPool->startFlag = 1;
    }
    return 0;
}
