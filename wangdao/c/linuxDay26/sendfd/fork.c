/*************************************************************************
	> File Name: fork.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-05-05 16:08:12
 ************************************************************************/

#include <func.h>

int sendFd(int pipefd,int fd)
{
    struct msghdr msg;
    bzero(&msg,sizeof(msg));
    struct iovec iov;

    char buf[10]="hello";
    iov.iov_base = buf;
    iov.iov_len = 5;

    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    struct cmsghdr *cmsg;
    size_t msglen = CMSG_LEN(sizeof(int));
    printf("msglen=%ld\n",msglen);
    cmsg = (struct cmsghdr*)malloc(msglen);

    cmsg->cmsg_len = msglen;
    cmsg->cmsg_level = SOL_SOCKET;
    //宏SOL_SOCKET表示只传递一个描述符
    cmsg->cmsg_type = SCM_RIGHTS;

    *(int*)CMSG_DATA(cmsg)=fd;
    printf("cmsgaddr=%p\n",cmsg);
    printf("CMSG_DATA addr=%p\n",CMSG_DATA(cmsg));

    msg.msg_control = cmsg;
    msg.msg_controllen =  msglen;

    int ret = sendmsg(pipefd,&msg,0);
    ERROR_CHECK(ret,-1,"sendmsg");

    return 0;
}
 
int recvFd(int pipefd,int* fd)
{
    struct msghdr msg;
    bzero(&msg,sizeof(msg));
    struct iovec iov;
    char buf[10]={0};
    iov.iov_base = buf;
    iov.iov_len = 10;
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    struct cmsghdr *cmsg; 
    size_t msglen = CMSG_LEN(sizeof(int));
    //msglen = 16+sizeof(int);
    printf("msglen=%ld\n",msglen);
    cmsg = (struct cmsghdr*)malloc(msglen);

    cmsg->cmsg_len = msglen;
    cmsg->cmsg_level = SOL_SOCKET;
    cmsg->cmsg_type = SCM_RIGHTS;

    msg.msg_control = cmsg;
    msg.msg_controllen =  msglen;
    int ret = recvmsg(pipefd,&msg,0);
    ERROR_CHECK(ret,-1,"sendmsg");

    printf("buf=%s\n",buf);

    *fd = *(int*)CMSG_DATA(cmsg);
    //把描述符取出来

    return 0;
}
int main()
{
    int fds[2];
    //创建一个全双工的管道,用于sendmsg
    socketpair(AF_LOCAL,SOCK_STREAM,0,fds);

    if(fork())
    {
        close(fds[0]);//管道读端为fds[0]，关闭管道读端
        int fd = open("file",O_RDWR);
        printf("fd=%d\n",fd);
        /* lseek(fd,5,SEEK_SET); */
        //相当于跨进程的dup
        sendFd(fds[1],fd);
        close(fd);
        wait(NULL);
    }
    else{
        close(fds[1]);
        int childfd = 0;
        char buf[128]={0};
        recvFd(fds[0],&childfd);
        sleep(1);
        printf("childfd=%d\n",childfd);
        read(childfd,buf,sizeof(buf));
        printf("bufmain=%s\n",buf);
        return 0;
    }
 
}

