#include "process_pool.h" 
//创建子进程，并初始化主数据结构
int makeChild(process_data_t *p,int processNum)
{
    int i;
    pid_t pid;
    int fds[2];//管道，用于父子进程通信
    int ret;
    for(i=0;i<processNum;i++)
    {
        //socketpair是全双工管道，任何一端都可以读写
        ret=socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
        ERROR_CHECK(ret,-1,"socketpair");
        pid=fork();
        //子进程创建好之后，执行childHandle
        if(0==pid)
        {
            close(fds[1]);
            childHandle(fds[0]);
        }
        //父进程，创建子进程之后，记录子进程的信息
        close(fds[0]);//关闭管道一端
        p[i].pid=pid;//子进程pid
        p[i].pipeFd=fds[1];//存储每个子进程的管道对端
        p[i].busy=0;
    }
    return 0;
}
int childHandle(int pipeFd)
{
    int newFd;
    char finishFlag;
    while(1)
    {
        recvFd(pipeFd,&newFd);//接收任务，没有任务时，子进程会睡觉
        tranFile(newFd);//给客户端发文件

        //关闭连接,服务器传递newFd给子进程时已经close一次，
        //所以此时newFd的引用计数为1，close之后就会断开连接
        close(newFd);
        write(pipeFd,&finishFlag,1);//子进程通知父进程完成任务啦
    }
}
