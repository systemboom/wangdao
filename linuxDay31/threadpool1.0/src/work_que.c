#include "../include/work_que.h"

int queInit(pQue_t pQue,int capacity)
{//任务队列初始化
    bzero(pQue,sizeof(Que_t));
    pQue->pHead = pQue->pTail = NULL;
    pQue->queSize = 0;
    pQue->queCapacity = capacity;
    pthread_mutex_init(&pQue->mutex,NULL);//初始化锁，属性默认为NULL
    return 0;
}

int queInsert(pQue_t pQue,pNode_t pNew)
{//任务队列的插入（尾插法）
    if(NULL == pQue->pHead)
    {
        pQue->pHead = pNew;
        pQue->pTail = pNew;
    }
    else{
        pQue->pTail->pNext = pNew;
        pQue->pTail = pNew;
    }
    pQue->queSize++;
    return 0;
}

int queGet(pQue_t pQue,pNode_t* pGet)
{//队列出队，获取头部元素
    if(NULL == pQue->pHead)
    {
        return -1;
    }
    *pGet = pQue->pHead;
    pQue->pHead = pQue->pHead->pNext;
    if(NULL == pQue->pHead)
    {
        pQue->pTail = NULL;
    }

    pQue->queSize--;
    return 0;

}
