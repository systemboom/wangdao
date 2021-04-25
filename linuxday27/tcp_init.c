#include "process_pool.h"


int tcpInit(int *socketFd,char* ip,char* port)
{

    int sfd = socket(AF_INET,SOCK_STREAM,0);
    ERROR_CHECK(sfd,-1,"socket");
    //sfd的值是未使用的最小的文件描述符的值
    printf("sfd=%d\n",sfd);

    struct sockaddr_in addr;
    bzero(&addr,sizeof(addr));
    addr.sin_family = AF_INET;//ip类型
    addr.sin_addr.s_addr = inet_addr(ip);//ip地址
    addr.sin_port = htons(atoi(port));//端口号
    //将主机序转网络序
    int ret;
    int reuse=1;
    ret = setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
    ERROR_CHECK(ret,-1,"setsockopt");

    //绑定ip地址和端口
    ret = bind(sfd,(struct sockaddr*)&addr,sizeof(addr));
    ERROR_CHECK(ret,-1,"bind");

    //监听对应的端口
    //listen的第二个参数表示已经完成三次握手的队列的大小
    listen(sfd,10);

    *socketFd = sfd;
    return 0;
}

