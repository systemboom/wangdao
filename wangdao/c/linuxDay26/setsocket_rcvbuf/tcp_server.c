/*************************************************************************
	> File Name: tcp_server.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-04-30 16:15:36
 ************************************************************************/

#include <func.h>

#define MAXFDNUM 10

int main(int argc, char* argv[])
{
    ARGS_CHECK(argc,3);

    int sfd = socket(AF_INET,SOCK_STREAM,0);
    ERROR_CHECK(sfd,-1,"socket");
    //sfd的值是未使用的最小的文件描述符的值
    printf("sfd=%d\n",sfd);

    struct sockaddr_in addr;
    bzero(&addr,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));

    int ret;
    int rcvBufSize = 8*1024;
    socklen_t Len = sizeof(rcvBufSize);

    ret = getsockopt(sfd,SOL_SOCKET,SO_RCVBUF,&rcvBufSize,&Len);
    printf("get recvBuf=%d\n",rcvBufSize);

    rcvBufSize = 8*1024;
    ret = setsockopt(sfd,SOL_SOCKET,SO_RCVBUF,&rcvBufSize,Len);
    ERROR_CHECK(ret,-1,"setsockopt");

    ret = getsockopt(sfd,SOL_SOCKET,SO_RCVBUF,&rcvBufSize,&Len);
    printf("after set recvBuf=%d\n",rcvBufSize);

    //绑定ip地址和端口
    ret = bind(sfd,(struct sockaddr*)&addr,sizeof(addr));
    ERROR_CHECK(ret,-1,"bind");

    //监听对应的端口
    //listen的第二个参数表示已经完成三次握手的队列的大小
    listen(sfd,10);

    struct sockaddr_in cli;
    bzero(&cli,sizeof(cli));

    //当有客户端连接的时候，我们接受对方的连接
    //产生新的newFd
    //代表服务器跟客户端的TCP连接
    socklen_t len=sizeof(cli);
    int newFd = accept(sfd,(struct sockaddr*)&cli,&len);
    ERROR_CHECK(newFd,-1,"accept");
    printf("client ip=%s,port=%d\n",inet_ntoa(cli.sin_addr),ntohs(cli.sin_port));
    
    char buf[1024]={0};
    //第四个参数改为MSG_PEEK
    ret = recv(newFd,buf,sizeof(buf),MSG_PEEK);
    printf("ret=%d,buf=%s\n",ret,buf);

    //第二次recv不会阻塞，因为第一次是MSG_PEEK方式
    //如果是MSG_PEEK,recv的时候只会从newFd的缓冲区中
    //把数据复制一份到buf里，内核的缓冲中仍然是保存
    //原来的数据
    ret = recv(newFd,buf,sizeof(buf),0);
    printf("ret=%d,buf=%s\n",ret,buf);
    close(newFd);
    close(sfd);
}
