#include <func.h>

#define MAXFDNUM 10

int main(int argc,char* argv[])
{

    int sfd;
    sfd = socket(AF_INET,SOCK_DGRAM,0);
    ERROR_CHECK(sfd,-1,"socket");

    struct sockaddr_in ser;
    bzero(&ser,sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_addr.s_addr = inet_addr(argv[1]);
    ser.sin_port = htons(atoi(argv[2]));

    int ret = 0;
    char buf[1024]={0};

    ret = sendto(sfd,"1",1,0,(struct sockaddr*)&ser,sizeof(ser));
    /* printf("sendto ret=%d\n",ret); */

    fd_set rdset;
    int readyNum=0;
    socklen_t sockLen = sizeof(ser);

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
                bzero(buf,sizeof(buf));
                read(STDIN_FILENO,buf,sizeof(buf));
                sendto(sfd,buf,strlen(buf)-1,0,(struct sockaddr*)&ser,sockLen);
            }

            if(FD_ISSET(sfd,&rdset))
            {
                bzero(buf,sizeof(buf));
                recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr*)&ser,&sockLen);
                printf("%s\n",buf); 
            }
        }

    }
 
}

