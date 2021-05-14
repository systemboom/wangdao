#include <func.h>

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,2);

    printf("argv[1]=%s\n",argv[1]);

    struct in_addr netIp;

    inet_aton(argv[1],&netIp);
    //把点分十进制的字符串转换成4个字节的网络字节序的ip
    
    printf("addr=%x\n",netIp.s_addr);//打印4个字节的网络字节序的ip

    printf("addr=%s\n",inet_ntoa(netIp));
    //把4个字节的网络字节序的ip 转换 成点分十进制的字符串

    printf("addr=%x\n",inet_addr(argv[1]));
    //inet_addr()若成功则返回32 位二进制的网络字节序地址
}

