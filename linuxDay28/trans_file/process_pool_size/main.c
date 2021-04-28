/*************************************************************************
	> File Name: main.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-05-06 10:00:55
 ************************************************************************/

#include "process_pool.h"

int main(int argc, char* argv[])
{
    ARGS_CHECK(argc,4);
    
    //1. 创建子进程并初始化结构体数组
    int processNum = atoi(argv[3]);
    process_data_t *pData = (process_data_t*)calloc(processNum,sizeof(process_data_t));
    makeChild(pData,processNum);

    //tcp初始化
    int socketFd;
    tcpInit(&socketFd,argv[1],argv[2]);
 
    int epfd = epoll_create(1);
    ERROR_CHECK(epfd,-1,"epoll_create");

    //把socketfd和管道的对端添加到epoll
    epollInAdd(epfd,socketFd); 
    int i=0,j=0;
    for(i=0;i<processNum;i++)
    {
        epollInAdd(epfd,pData[i].pipefd);
    }

    int readyNum=0;
    char flag=0;
    int newFd = 0;
    struct epoll_event *evs;
    evs = (struct epoll_event*)calloc(processNum+1,sizeof(struct epoll_event));

    while(1)
    {
        readyNum = epoll_wait(epfd,evs,processNum+1,-1);
        for(i=0;i<readyNum;i++)
        {
            if(evs[i].data.fd == socketFd)
            {
                newFd = accept(socketFd,NULL,NULL);
                ERROR_CHECK(newFd,-1,"accept");
                for(j=0;j<processNum;j++)
                {
                    if(0 == pData[j].busy)
                    {
                        //sendFd相当于dup机制
                        //文件的引用计数加1
                        sendFd(pData[j].pipefd,newFd);
                        //把子进程标记为忙碌
                        pData[j].busy = 1;
                        printf("child %d is busy\n",pData[j].pid);
                        //相当于引用计数减一
                        close(newFd);
                        break;
                    }
                }
            }
            else{
                //当管道可读的时候，代表子进程完成任务，通知了父进程
                //父进程找到对应的子进程，标记成非忙碌状态
                for(j=0;j<processNum;j++)
                {
                    if(evs[i].data.fd == pData[j].pipefd)
                    {
                        //把管道中的数据读出来，不然管道就会一直可读
                        read(pData[j].pipefd,&flag,1);
                        pData[j].busy = 0;
                        printf("child %d is not busy\n",pData[j].pid);
                    }
                }
            }
        }
    }
}
