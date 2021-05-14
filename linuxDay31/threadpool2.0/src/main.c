#include "../include/head.h"
#include "../include/work_que.h"
#include "../include/thread_pool.h"

int exitPipe[2];
void sigFunc(int signum)
{
    char exitFlag=1;
    write(exitPipe[1],&exitFlag,1);
        
}
int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,5);
    //argv[1]ip地址
    //argv[2]端口号
    //argv[3]线程池中子线程数量
    //argv[4]线程池能力
    
    //让子进程实现线程池
    //父进程负责信号，负责通知退出
    
    if(fork())
    {
        signal(SIGUSR1,sigFunc);
        wait(NULL);//等待子进程（线程池）退出
        exit(0);//子进程退出之后，自己退出
    }
    ThreadPool_t threadPool;
    bzero(&threadPool,sizeof(ThreadPool_t));

    int threadNum = atoi(argv[3]);
    int capacity = atoi(argv[4]);
    threadPoolInit(&threadPool,threadNum,capacity);

    threadPoolStart(&threadPool);

    int socketFd;
    tcpInit(&socketFd,argv[1],argv[2]);
    //主线程启动listen，监听客户端连接请求

    int epfd = epoll_create(1);//创建epoll
    ERROR_CHECK(epfd,-1,"epoll_create");
    
    struct epoll_event evs[2];//创建events结构体数组监控socket描述符
    bzero(evs,2*sizeof(struct epoll_event));

    epollInAdd(epfd,socketFd);//将socket描述符添加到监听
    epollInAdd(epfd,exitPipe[0]);
    int readyNum=0;
    int i=0;
    int newFd = 0;
    while(1)
    {
        readyNum = epoll_wait(epfd,evs,2,-1);
        //若events结构体数组中有事件唤醒则返回唤醒事件的数量，这里返回的是
        //-1表示一直等待，直到有事件唤醒
        for(i=0;i<readyNum;i++)
        {
            if(evs[i].data.fd == socketFd)
            {//有客户端连接
                newFd = accept(socketFd,NULL,NULL);
                //第二个参数是包含客户端一些信息的结构体，不关心就填NULL
                //第三个参数是第二个参数的大小
                
                pNode_t pNew = (pNode_t)malloc(sizeof(Node_t));
                //将客户端请求封装成任务节点，插到任务队列中

                pNew->clientFd = newFd;//客户端的socket描述符
                
                pthread_mutex_lock(&threadPool.que.mutex);
                //主线程（生产者）向任务队列中添加任务节点涉及到访问线程之间的共享资源，所以要加锁

                queInsert(&threadPool.que,pNew);//将pNew插入到任务队列threadPool中
                
                pthread_mutex_unlock(&threadPool.que.mutex);//解锁
              
                pthread_cond_signal(&threadPool.cond);  //通知子线程（消费者）
            }
            if(evs[i].data.fd==exitPipe[0])
            {
                //执行退出流程
                //1.for循环给所有子进程发cancel信号 
                
                //2.把startFlag标记0；
                //子线程每次判断startFlag==0，表示要退出
                //执行pthread_exit(0)退出
                
                pthread_cond_broadcast(&threadPool.cond);
                //唤醒所有睡眠在条件变量上的子线程
                
                for(int i=0;i<threadPool.threadNum;i++)
                {
                    //循环等待子线程
                    pthread_join(threadPool.pthid[i],NULL);
                }
            }
        }
    }
}
