#include <func.h>

#define MAXFDNUM 10

int main(int argc, char* argv[])
{
    int sfd;
    sfd = socket(AF_INET,SOCK_DGRAM,0);
    ERROR_CHECK(sfd,-1,"socket");

    struct sockaddr_in ser;
    bzero(&ser,sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_addr.s_addr = inet_addr(argv[1]);
    ser.sin_port = htons(atoi(argv[2]));

    int ret ;
    ret = bind(sfd,(struct sockaddr*)&ser,sizeof(ser));
    ERROR_CHECK(ret,-1,"bind");

    //通过recvfrom拿到客户端的ip和端口信息
    struct sockaddr_in cli;
    bzero(&ser,sizeof(cli));
    socklen_t sockLen = sizeof(cli);
    char buf[10]={0};

    fd_set rdset;
    int readyNum=0;

    recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr*)&cli,&sockLen);
    while(1)
    {
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(sfd,&rdset);
        readyNum = select(MAXFDNUM,&rdset,NULL,NULL,NULL);
        if(readyNum>0)
        {
            if(FD_ISSET(STDIN_FILENO,&rdset))
            {
                bzero(buf,sizeof(buf));//先做清空，再读标准输入
                read(STDIN_FILENO,buf,sizeof(buf));
                sendto(sfd,buf,strlen(buf)-1,0,(struct sockaddr*)&cli,sockLen);
            }

            if(FD_ISSET(sfd,&rdset))
            {
                bzero(buf,sizeof(buf));
                recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr*)&cli,&sockLen);
                printf("%s\n",buf); 
            }
        }

    }



}
