#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include "head.h"
#include "work_que.h"
 
//线程池结构体
typedef struct {
    Que_t que;//任务队列
    int threadNum;//子线程数量
    pthread_t* pthid;//子线程ID
    pthread_cond_t cond;//条件变量，用于主线程和子线程之间的同步
    short startFlag;//启动标志位
}ThreadPool_t,*pThreadPool_t;

int threadPoolInit(pThreadPool_t pPool,int threadNum,int capacity);//线程池初始化
//参数：线程池结构体指针、线程数量、任务队列能力上限

int threadPoolStart(pThreadPool_t);//线程池启动/创建子线程

#endif
