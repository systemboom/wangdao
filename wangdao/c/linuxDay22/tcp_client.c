#include <func.h>

int main(int argc, char* argv[])
{

    ARGS_CHECK(argc,3);

    int sfd = socket(AF_INET,SOCK_STREAM,0);//参数：ipv4，tcp
    ERROR_CHECK(sfd,-1,"socket");

    struct sockaddr_in addr;
    bzero(&addr,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    //inet_addr返回将点分十进制转化后的无符号32位网络字节序
    addr.sin_port = htons(atoi(argv[2]));
    //atoi将端口号转化为整型数
    //htons将一个无符号短整型数值转化为网络字节序，即大端模式(big-endian)

    int ret ;
    ret = connect(sfd,(struct sockaddr*)&addr,sizeof(addr));
    //参数：socketfd，addr，addr大小，addr为传入参数
    //bind的函数原型的第二个是老的addr，所以要做一个类型转换
    ERROR_CHECK(ret,-1,"connect");

    char buf[1024]={0};
    recv(sfd,buf,sizeof(buf),0);
    
    printf("buf=%s\n",buf);

    send(sfd,"helloserver",11,0);

    while(1);
    close(sfd);

    return 0;
}
