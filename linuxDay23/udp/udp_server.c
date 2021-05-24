#include <func.h>

int main(int argc, char* argv[])
{
    int sfd;
    sfd = socket(AF_INET,SOCK_DGRAM,0);
    //参数：ipv4  udp 0

    ERROR_CHECK(sfd,-1,"socket");

    struct sockaddr_in ser;
    bzero(&ser,sizeof(ser));
    
    ser.sin_family = AF_INET;//ip类型为ipv4  
    ser.sin_addr.s_addr = inet_addr(argv[1]);//
    //点分十进制转字节序
    ser.sin_port = ntohs(atoi(argv[2]));
    //网络字节序转主机字节序
    int ret ;
    ret = bind(sfd,(struct sockaddr*)&ser,sizeof(ser));//绑定ip和端口
    ERROR_CHECK(ret,-1,"bind");

    struct sockaddr_in cli;//通过recvfrom拿到客户端的ip和端口信息
    bzero(&ser,sizeof(cli));

    socklen_t sockLen = sizeof(cli);//cli大小，用于给recvfrom传参
    char buf[1024]={0};
    recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr*)&cli,&sockLen);

    printf("%s\n",buf); 
    sendto(sfd,"helloudp",8,0,(struct sockaddr*)&cli,sockLen);

    while(1);
}

