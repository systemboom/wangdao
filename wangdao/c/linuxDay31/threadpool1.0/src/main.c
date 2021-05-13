#include "../include/head.h"
#include "../include/work_que.h"
#include "../include/thread_pool.h"

//传参 ip 端口 线程数量  队列capacity
int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,5);
    ThreadPool_t threadPool;
    bzero(&threadPool,sizeof(ThreadPool_t));

    int threadNum = atoi(argv[3]);
    int capacity = atoi(argv[4]);
    threadPoolInit(&threadPool,threadNum,capacity);//初始化线程池

    threadPoolStart(&threadPool);//启动线程池
    
    while(1);
}
