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
    int newFd;

    fd_set rdset;
    fd_set needMonitorSet;


    FD_ZERO(&rdset);
    //rdset只用过一个临时的集合，用于表示哪些描述符就绪
    FD_ZERO(&needMonitorSet);
    //因为rdset经过select会发生改变，所以用needMonitorSet去保存监听的描述符

    FD_SET(STDIN_FILENO,&needMonitorSet);
    FD_SET(sfd,&needMonitorSet);
    
    char buf[1024]={0};
    //表示select返回的就绪描述符的数量
    int readyNum=0;

    while(1)
    {
        //每次把监听的描述符从needMonitorSet传给rdset，
        //相当于rdset是一个临时的描述符集合，select每次只修改这个临时
        //集合，对真正记录集合的neeMonitorSet没有影响
        memcpy(&rdset,&needMonitorSet,sizeof(fd_set));
        //sizeof(fd_set)和sizeof(rdset)是一样的，反正大小一样

        readyNum = select(MAXFDNUM,&rdset,NULL,NULL,NULL);
        if(readyNum > 0)
        {
            //sfd就绪，代表有客户端连接，可以accept
            if(FD_ISSET(sfd,&rdset))
            {//监听套接字就绪的时候，就可以accept了
                newFd = accept(sfd,NULL,NULL);
                ERROR_CHECK(newFd,-1,"accept");
                FD_SET(newFd,&needMonitorSet);
            }
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
                    //对端断开，把newFd从需要监听的集合里删除
                    printf("byebye\n");
                    FD_CLR(newFd,&needMonitorSet);
                    //将newFd送集合中删掉
                    //关闭连接
                    close(newFd);
                }
                else
                    printf("%s\n",buf);
            }
        }

    }

    close(newFd);
    close(sfd);

}
