#include <func.h>

int main(int argc,char* argv[])
{

    int sfd;
    sfd = socket(AF_INET,SOCK_DGRAM,0);
    ERROR_CHECK(sfd,-1,"socket");

    struct sockaddr_in ser;
    bzero(&ser,sizeof(ser));
    ser.sin_family = AF_INET;
    ser.sin_addr.s_addr = inet_addr(argv[1]);
    ser.sin_port = ntohs(atoi(argv[2]));

    int ret = 0;
    char buf[1024]={0};

    ret = sendto(sfd,"helloserver",11,0,(struct sockaddr*)&ser,sizeof(ser));
    printf("sendto ret=%d\n",ret);

    socklen_t sockLen=sizeof(ser);
    ret = recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr*)&ser,&sockLen);
    printf("recvfrom ret=%d",ret);
    printf("buf=%s\n",buf);

    while(1);
 
}
