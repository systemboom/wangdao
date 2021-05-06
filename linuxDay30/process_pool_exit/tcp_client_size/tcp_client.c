/*************************************************************************
	> File Name: tcp_client.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-04-30 16:38:26
 ************************************************************************/

#include <func.h>

#define MAXFDNUM 10

int recvCycle(int,void*,int);
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

    int dataLen = 0;
    char buf[1000]={0};

    //先接文件名
    recvCycle(sfd,&dataLen,4);
    recvCycle(sfd,buf,dataLen);

    //打开文件
    int fd = open(buf,O_RDWR|O_CREAT,0666);
    ERROR_CHECK(fd,-1,"open");

    //接收文件大小
    size_t fileSize=0;
    recvCycle(sfd,&dataLen,4);
    recvCycle(sfd,&fileSize,dataLen);
    printf("fileSize=%ld\n",fileSize);
    size_t recvSize=0,lastSize=0;//记录一共接了多少字节

    size_t slice = fileSize/1000;

    //循环接收文件内容
    while(1)
    {
        recvCycle(sfd,&dataLen,4);
        if(0 == dataLen)
        {
            break;
        }
        ret = recvCycle(sfd,buf,dataLen);
        if(-1 == ret)
        {
            printf("error\n");
            break;
        }
        ret = write(fd,buf,dataLen);
        recvSize+=ret;
        if(recvSize-lastSize>=slice)
        {
            printf("%5.2f%s\r",(float)recvSize/fileSize*100,"%");
            fflush(stdout);
            lastSize = recvSize;
        }
    }

    printf("recvSize=%ld\n",recvSize);
    printf("100.00%%\n");
    close(fd);
    close(sfd);
    return 0;
}
