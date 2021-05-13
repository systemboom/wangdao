#include "process_pool.h"

int makeChild(process_data_t* p,int processNum)
{
    int fds[2];
    int ret =0;
    pid_t pid;
    for(int i=0;i<processNum;i++)
    {
        //全双工管道
        ret = socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
        ERROR_CHECK(ret,-1,"socketpair");
        pid = fork();
        if(0 == pid)
        {
            close(fds[1]);
            childHandle(fds[0]);
        }
        close(fds[0]);
        p[i].busy = 0;
        p[i].pid = pid;
        p[i].pipefd = fds[1];
        printf("child pid=%d,pipe=%d\n",pid,fds[1]);
    }
    return 0;
}

int childHandle(int pipefd)
{
    int newFd = 0;
    char flag=0;
    char exitFlag;
    while(1)
    {
        recvFd(pipefd,&newFd,&exitFlag);
        //如果exitFlag拿到的是1，子进程退出
        //如果是0，代表发来的客户端newFd，传输文件
        if(1 == exitFlag)
        {
            printf("child exit\n");
            exit(0);
        }
        printf("newFd=%d\n",newFd);
        transFile(newFd);
        //断开连接
        close(newFd);
        write(pipefd,&flag,1);
    }
}

