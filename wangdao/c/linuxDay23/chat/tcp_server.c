#include <func.h>

#define MAXFDNUM 10

int main(int argc, char* argv[])
{
    ARGS_CHECK(argc,3);

    int sfd = socket(AF_INET,SOCK_STREAM,0);
    ERROR_CHECK(sfd,-1,"socket");
    printf("sfd=%d\n",sfd);

    struct sockaddr_in addr;
    bzero(&addr,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));

    int ret;
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
    //ntoa：网络字节序转点分十进制
    //ntohs：网络字节序转主机字节序

    fd_set rdset;//文件描述符集合
    char buf[1024]={0};
    //表示select返回的就绪描述符的数量
    int readyNum=0;

    while(1)
    {
        FD_ZERO(&rdset);//清空文件描述符集合
        FD_SET(STDIN_FILENO,&rdset); //将标准输入添加到rdset
        FD_SET(newFd,&rdset);//将newFd添加到rdset 
        readyNum = select(MAXFDNUM,&rdset,NULL,NULL,NULL);
        if(readyNum > 0)
        {//有描述符就绪，判断是是谁就绪
            if(FD_ISSET(STDIN_FILENO,&rdset))
            {//检查STDIN_FILENO是否可用
                bzero(buf,sizeof(buf));
                read(STDIN_FILENO,buf,sizeof(buf));
                
                send(newFd,buf,strlen(buf)-1,0);
                //读标准输入的时候会回车，\n也会被读进buf里，-1表示最后的\n不发送
            }
            else if(FD_ISSET(newFd,&rdset))
            {//检查newFd是否可用
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

