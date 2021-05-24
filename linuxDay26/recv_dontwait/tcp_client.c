/*************************************************************************
	> File Name: tcp_client.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-04-30 16:38:26
 ************************************************************************/

#include <func.h>

#define MAXFDNUM 10
int main(int argc, char* argv[])
{

    ARGS_CHECK(argc,3);

    int sfd = socket(AF_INET,SOCK_STREAM,0);
    ERROR_CHECK(sfd,-1,"socket");

    struct sockaddr_in addr;
    bzero(&addr,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));
 
    int ret ;
    ret = connect(sfd,(struct sockaddr*)&addr,sizeof(addr));
    ERROR_CHECK(ret,-1,"connect");

    while(1);

    fd_set rdset;
    char buf[1024]={0};
    //表示select返回的就绪描述符的数量
    int readyNum=0;

}
