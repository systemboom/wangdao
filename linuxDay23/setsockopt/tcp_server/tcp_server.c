/*************************************************************************
	> File Name: tcp_server.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-04-30 16:15:36
 ************************************************************************/

#include <func.h>

#define MAXFDNUM 10

int main(int argc, char* argv[])
{
    ARGS_CHECK(argc,3);

    int sfd = socket(AF_INET,SOCK_STREAM,0);
    ERROR_CHECK(sfd,-1,"socket");
    //sfd的值是未使用的最小的文件描述符的值
    printf("sfd=%d\n",sfd);

    struct sockaddr_in addr;
    bzero(&addr,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));

    int reuse = 1;//为1代表可以重用地址，0代表不可重用
    //允许重用地址，就是可以绑定TIME_WAIT状态的端口
    int ret;
    ret = setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));

    //绑定ip地址和端口
    ret = bind(sfd,(struct sockaddr*)&addr,sizeof(addr));
    ERROR_CHECK(ret,-1,"bind");

    //监听对应的端口
    //listen的第二个参数表示已经完成三次握手的队列的大小
    listen(sfd,3);

    struct sockaddr_in cli;
    bzero(&cli,sizeof(cli));

    //当有客户端连接的时候，我们接受对方的连接
    //产生新的newFd
    //代表服务器跟客户端的TCP连接
    socklen_t len=sizeof(cli);
    int newFd = accept(sfd,(struct sockaddr*)&cli,&len);
    ERROR_CHECK(newFd,-1,"accept");
    printf("client ip=%s,port=%d\n",inet_ntoa(cli.sin_addr),ntohs(cli.sin_port));

    fd_set rdset;
    char buf[1024]={0};
    //表示select返回的就绪描述符的数量
    int readyNum=0;

    while(1)
    {
        FD_ZERO(&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        FD_SET(newFd,&rdset);
        readyNum = select(MAXFDNUM,&rdset,NULL,NULL,NULL);
        if(readyNum > 0)
        {
            if(FD_ISSET(STDIN_FILENO,&rdset))
            {
                bzero(buf,sizeof(buf));
                read(STDIN_FILENO,buf,sizeof(buf));
                //-1表示最后的\n不发送
                send(newFd,buf,strlen(buf)-1,0);
            }
            else if(FD_ISSET(newFd,&rdset))
            {
                bzero(buf,sizeof(buf));
                //客户端断开的时候，内核会把newFd标记为可读
                //select就会一直检测到newFd是可读的
                //就会一直进入到这个分支
                ret = recv(newFd,buf,sizeof(buf),0);
                //对端断开的退出机制
                //当对方断开，recv的返回值为0
                if(ret == 0)
                {
                    printf("byebye\n");
                    break;
                }
                printf("%s\n",buf);
            }
        }

    }

    close(newFd);
    close(sfd);

}
