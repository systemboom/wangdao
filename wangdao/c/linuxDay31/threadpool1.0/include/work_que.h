#ifndef __WORK_QUE_H__
#define __WORK_QUE_H__
#include "head.h"

//任务节点
typedef struct node{
    int clientFd;//客户端的socket描述符
    struct node* pNext;//指向下一个结点的指针
}Node_t,*pNode_t;

//队列结构体
typedef struct{
    pNode_t pHead,pTail;//队列头和队列尾指针
    int queSize;//队列大小
    int queCapacity;//队列能力
    pthread_mutex_t mutex;//锁
}Que_t,*pQue_t;

int queInit(pQue_t pQue,int capacity);//队列初始化
int queInsert(pQue_t pQue,pNode_t pNew);//队列插入
int queGet(pQue_t pQue,pNode_t* pGet);//队列获取结点
#endif
