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

    fd_set rdset;
    char buf[1024]={0};
    //表示select返回的就绪描述符的数量
    int readyNum=0;

    while(1)
    {
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(sfd,&rdset);
        readyNum = select(MAXFDNUM,&rdset,NULL,NULL,NULL);
        if(readyNum > 0)
        {
            if(FD_ISSET(STDIN_FILENO,&rdset))
            {
                bzero(buf,sizeof(buf));
                read(STDIN_FILENO,buf,sizeof(buf));
                //-1表示最后的\n不发送
                send(sfd,buf,strlen(buf)-1,0);
            }
            else if(FD_ISSET(sfd,&rdset))
            {
                bzero(buf,sizeof(buf));
                ret = recv(sfd,buf,sizeof(buf),0);
                if(ret == 0)
                {
                    printf("byebye server\n");
                    break;
                }
                printf("%s\n",buf);
            }
        }
    }


    close(sfd);

    return 0;
}

