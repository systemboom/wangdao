/*************************************************************************
	> File Name: work_que.h
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-05-11 10:07:20
 ************************************************************************/

#ifndef __WORK_QUE_H__
#define __WORK_QUE_H__
#include "head.h"

//任务节点
typedef struct node{
    int clientFd;//客户端的socket描述符
    struct node* pNext;
}Node_t,*pNode_t;

typedef struct{
    pNode_t pHead,pTail;//队列头和队列尾指针
    int queSize;
    int queCapacity;
    pthread_mutex_t mutex;
}Que_t,*pQue_t;

int queInit(pQue_t pQue,int capacity);
int queInsert(pQue_t pQue,pNode_t pNew);
int queGet(pQue_t pQue,pNode_t* pGet);
#endif
