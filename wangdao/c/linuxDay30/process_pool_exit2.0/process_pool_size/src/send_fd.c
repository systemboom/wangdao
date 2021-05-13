/*************************************************************************
	> File Name: fork.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-05-05 16:08:12
 ************************************************************************/

#include "process_pool.h"

int sendFd(int pipefd,int fd,char exitFlag)
{
    struct msghdr msg;
    bzero(&msg,sizeof(msg));
    struct iovec iov;
    iov.iov_base = &exitFlag;
    iov.iov_len = 1;
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    struct cmsghdr *cmsg;
    size_t msglen = CMSG_LEN(sizeof(int));
    cmsg = (struct cmsghdr*)malloc(msglen);

    cmsg->cmsg_len = msglen;
    cmsg->cmsg_level = SOL_SOCKET;
    cmsg->cmsg_type = SCM_RIGHTS;

    *(int*)CMSG_DATA(cmsg)=fd;

    msg.msg_control = cmsg;
    msg.msg_controllen =  msglen;

    int ret = sendmsg(pipefd,&msg,0);
    ERROR_CHECK(ret,-1,"sendmsg");

    return 0;
}

int recvFd(int pipefd,int* fd,char* exitFlag)
{
    struct msghdr msg;
    bzero(&msg,sizeof(msg));
    struct iovec iov;
    /* char buf[10]={0}; */
    iov.iov_base = exitFlag;
    iov.iov_len = 1;
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    struct cmsghdr *cmsg;
    size_t msglen = CMSG_LEN(sizeof(int));
    //msglen = 16+sizeof(int);
    cmsg = (struct cmsghdr*)malloc(msglen);

    cmsg->cmsg_len = msglen;
    cmsg->cmsg_level = SOL_SOCKET;
    cmsg->cmsg_type = SCM_RIGHTS;

    msg.msg_control = cmsg;
    msg.msg_controllen =  msglen;
    int ret = recvmsg(pipefd,&msg,0);
    ERROR_CHECK(ret,-1,"sendmsg");


    *fd = *(int*)CMSG_DATA(cmsg);

    return 0;
}

