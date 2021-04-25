#include "process_pool.h"

int makeChild(process_data_t* p,int processNum)
{
    int fds[2];
    int ret =0;
    pid_t pid;
    for(int i=0;i<processNum;i++)
    {
        
        ret = socketpair(AF_LOCAL,SOCK_STREAM,0,fds);//全双工管道

        ERROR_CHECK(ret,-1,"socketpair");
        pid = fork();
        if(0 == pid)
        {//父进程继续for循环，子进程就在这if里
            close(fds[1]);
            childHandle(fds[0]);
            //子进程一会要在childHanle中接收文件描述符
            //所以把管道传进来
        }
        close(fds[0]);
        //父进程使用的是fds[1]，所以把fds[0]关掉
        p[i].busy = 0;
        p[i].pid = pid;
        p[i].pipefd = fds[1];//父进程使用的是fds[1]
        printf("child pid=%d,pipe=%d\n",pid,fds[1]);
    }
    return 0;
}

int childHandle(int pipefd)
{
    int newFd = 0;
    char flag=0;
    while(1)
    {
        recvFd(pipefd,&newFd);
        printf("newFd=%d\n",newFd);
        int ret = send(newFd,"helloclient",11,0);//代表传输文件
        printf("ret=%d\n",ret);
        
        close(newFd); //断开连接
        write(pipefd,&flag,1);//把管道中的数据读出来，不然管道就会一直可读，
    }
}

