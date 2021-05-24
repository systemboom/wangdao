/*************************************************************************
	> File Name: epoll.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-05-06 11:03:27
 ************************************************************************/

#include "../include/head.h"

int epollInAdd(int epfd,int fd)
{
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;
    int ret=0;
    ret = epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl");

    return 0;
}
