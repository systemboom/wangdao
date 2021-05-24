/*************************************************************************
	> File Name: work_que.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-05-11 11:27:03
 ************************************************************************/

#include "../include/work_que.h"

int queInit(pQue_t pQue,int capacity)
{
    bzero(pQue,sizeof(Que_t));
    pQue->pHead = pQue->pTail = NULL;
    pQue->queSize = 0;
    pQue->queCapacity = capacity;
    pthread_mutex_init(&pQue->mutex,NULL);
    return 0;
}

int queInsert(pQue_t pQue,pNode_t pNew)
{
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
{//用于给子线程获取任务队列中的任务节点
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
