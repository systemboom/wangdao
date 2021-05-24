#include <func.h>

int main(int argc, char* argv[])
{
    ARGS_CHECK(argc,3);

    int sfd = socket(AF_INET,SOCK_STREAM,0);
    //ipv4，tcp

    ERROR_CHECK(sfd,-1,"socket");
    printf("sfd=%d\n",sfd);

    struct sockaddr_in addr;
    bzero(&addr,sizeof(addr));
    addr.sin_family = AF_INET;//ipv4
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    //inet_addr返回转化后的无符号32位网络字节序

    addr.sin_port = htons(atoi(argv[2]));
    //atoi将端口号转化为整型数
    //htons转化为网络字节序

    int ret;
    //绑定ip地址和端口
    ret = bind(sfd,(struct sockaddr*)&addr,sizeof(addr));
    //参数：socketfd，addr，addr大小，addr为传入参数
    //bind的函数原型的第二个是老的addr，所以要做一个类型转换
    ERROR_CHECK(ret,-1,"bind");

    //监听对应的端口
    listen(sfd,10);

    struct sockaddr_in cli;//accpet产生的新的套接字
    bzero(&cli,sizeof(cli));

    //当有客户端连接的时候，我们接受对方的连接
    //产生新的newFd
    socklen_t len=sizeof(cli);
    int newFd = accept(sfd,(struct sockaddr*)&cli,&len);
    //第二个参数为传出参数，会把远程主机的信息（远程主机的地址和
    //端口号信息）保存到这个指针所指的结构体中
    ERROR_CHECK(newFd,-1,"accept");

    char buf[1024]={0};
    send(newFd,"helloclient",10,0);

    /* recv(newFd,buf,sizeof(buf),0); */
    read(newFd,buf,sizeof(buf));
    printf("recv=%s\n",buf);

    while(1);
    close(newFd);
    close(sfd);


}

