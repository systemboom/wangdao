#include "process_pool.h"
// 传参 ip地址，端口号，进程数
int main(int argc,char* argv[])
{
    if(argc!=4)
    {
        printf("./process_pool_server ip port process_num\n");
        return -1;
    }
    int processNum=atoi(argv[3]);//得到进程数
    //分配保存子进程结构体数组的空间
    process_data_t *pData=(process_data_t*)calloc(processNum,sizeof(process_data_t));
    
    //1.创建子进程
    makeChild(pData,processNum);
    int i;
#ifdef DEBUG
    for(i=0;i<processNum;i++)
    {
        printf("pid=%d pipeFd=%d\n",pData[i].pid,pData[i].pipeFd);
    }
#endif
    //2.初始化TCP
    int socketFd;
    tcpInit(&socketFd,argv[1],argv[2]);//初始化socket并开启监听

    //3.创建epoll，监听socketFd和管道
    int epfd=epoll_create(1);
    struct epoll_event *evs;
    evs=(struct epoll_event*)calloc(processNum+1,sizeof(struct epoll_event));
    //把socketFd添加到epoll中监听
    epollInAdd(epfd,socketFd);

    //遍历的方式添加管道
    for(i=0;i<processNum;i++)
    {
        //添加管道读端到epoll中，当子进程非忙碌时，写管道，
        //父进程就知道子进程完成任务，可以再次分配任务了
        epollInAdd(epfd,pData[i].pipeFd);//注册监听每一个子进程的管道对端
    }
    int readyFdCount,newFd,j;
    char noBusyflag;

    //开始等待socketFd和管道就绪
    while(1)
    {
        readyFdCount=epoll_wait(epfd,evs,processNum+1,-1);
        for(i=0;i<readyFdCount;i++)
        {
            if(evs[i].data.fd==socketFd)
            {
                newFd=accept(socketFd,NULL,NULL);//接收客户端请求
                //遍历的方式找到非忙碌子进程
                for(j=0;j<processNum;j++)
                {
                    if(0==pData[j].busy)
                    {
                        sendFd(pData[j].pipeFd,newFd);//把任务发给对应的子进程
                        pData[j].busy=1;//子进程标识为忙碌
                        printf("%d pid is busy\n",pData[j].pid);
                        break;
                    }
                }
                //每次有客户端连接都会执行close。
                //1.如果有空闲子进程，newFd发给子进程，newFd的引用计数为2，这里执行close之后
                //newFd的引用计数变为1，这样，子进程发送完文件之后，再close(newFd)，才会真正断开连接
                //2.如果没有空闲的子进程，这里直接close,客户端会断开，不会发文件给客户端
                //客户端可以过一会再来连接。
                close(newFd);
            }

            //遍历所有的管道，如果有管道可读，说明子进程完成任务
            //找到对应的子进程，读出管道的内容，并标记子进程为空闲状态
            for(j=0;j<processNum;j++)
            {
                if(evs[i].data.fd==pData[j].pipeFd)
                {
                    read(pData[j].pipeFd,&noBusyflag,1);//收到子进程的通知
                    pData[j].busy=0;//子进程设置为非忙碌
                    printf("%d pid is not busy\n",pData[j].pid);
                    break;
                }
            }
        }
    }
    return 0;
}

