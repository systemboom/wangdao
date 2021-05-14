#include "process_pool.h"

int epollInAdd(int epfd,int fd)
{
    struct epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;//读事件 
    int ret=0;
    ret = epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl");

    return 0;
}

