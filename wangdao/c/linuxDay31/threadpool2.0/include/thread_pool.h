/*************************************************************************
	> File Name: thread_pool.h
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-05-11 10:06:25
 ************************************************************************/

#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include "head.h"
#include "work_que.h"
 
typedef struct {
    Que_t que;//任务队列
    int threadNum;//子线程数量
    pthread_t* pthid;//子线程ID
    pthread_cond_t cond;//条件变量，用于主线程和子线程之间的同步
    short startFlag;//启动标志位
}ThreadPool_t,*pThreadPool_t;

int threadPoolInit(pThreadPool_t pPool,int threadNum,int capacity);
int threadPoolStart(pThreadPool_t);
#endif
