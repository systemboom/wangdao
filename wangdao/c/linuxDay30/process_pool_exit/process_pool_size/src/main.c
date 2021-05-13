#include "process_pool.h"

int exitPipe[2];

void sigExitFunc(int signum)
{//signum为信号，在sigExitFunc内给子进程发送退出信号

    printf("%d is comming\n",signum);
    char exitFlag=1;
    write(exitPipe[1],&exitFlag,1);
    //其实往管道里写什么不重要，只要让epoll知道管道可读就行了
}

int main(int argc, char* argv[])
{
    ARGS_CHECK(argc,4);

    pipe(exitPipe);//定义一个专门用于退出进程的管道
    
    //1. 创建子进程并初始化结构体数组
    int processNum = atoi(argv[3]);
    process_data_t *pData = (process_data_t*)calloc(processNum,sizeof(process_data_t));

    makeChild(pData,processNum);

    signal(SIGUSR1,sigExitFunc);
    //SIGUSR1为用户自定义信号，默认用于处理 进程终止
    //tip：signal(SIGUSR1,sigExitFunc);这行代码一定要放在makeChild(pData,processNum);的
    //后面，因为子进程是父进程fork出来的，子进程相当于是父进程的”一种拷贝“，signal放在makeChild
    //前面，会导致signal也被拷贝到子进程，子进程也会有信号处理函数，也会捕捉到到10号信号，但我们
    //只想让父进程捕捉到10号信号，所以放在后面。

    //tcp初始化
    int socketFd;
    tcpInit(&socketFd,argv[1],argv[2]);
 
    int epfd = epoll_create(1);
    ERROR_CHECK(epfd,-1,"epoll_create");

    
    epollInAdd(epfd,socketFd); 
    //把socketfd和管道的对端添加到epoll
    
    epollInAdd(epfd,exitPipe[0]); 
    //监听退出的管道的读端
    //一旦管道可读，就表示要退出，执行有序退出

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
            {//如果就绪描述符是socket描述符
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
            else if(evs[i].data.fd == exitPipe[0])
            {//如果就绪描述符是管道读端，执行退出流程
                for(j=0;j<processNum;j++)
                {//给每个子进程发送退出信号
                    kill(pData[j].pid,SIGUSR1);
                }
                for(j=0;j<processNum;j++)
                {
                    wait(NULL);
                    //等待子进程退出，父进程在此阻塞，直到子进程全部退出
                }
                printf("ready to exit\n");
                exit(0);
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

