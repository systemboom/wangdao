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
    listen(sfd,10);

    struct sockaddr_in cli;
    bzero(&cli,sizeof(cli));

    //当有客户端连接的时候，我们接受对方的连接
    //产生新的newFd
    //代表服务器跟客户端的TCP连接
    socklen_t len=sizeof(cli);
    int newFd = accept(sfd,(struct sockaddr*)&cli,&len);
    ERROR_CHECK(newFd,-1,"accept");
    printf("client ip=%s,port=%d\n",inet_ntoa(cli.sin_addr),ntohs(cli.sin_port));

    //创建epoll句柄
    int epfd = epoll_create(1);
    ERROR_CHECK(epfd,-1,"epoll_create");

    //向epoll里注册需要监听的文件描述符以及对应的事件
    
    struct epoll_event event,evts[2];
    //先注册标准输入的读事件
    event.events = EPOLLIN;//注册对应的事件，读
    event.data.fd = STDIN_FILENO;//注册需要监听的描述符添加到结构体里

    ret = epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&event);
    //参数：epoll句柄，动作（注册新fd到epfd），需要监听的文件描述符，event

    ERROR_CHECK(ret,-1,"epoll_ctl");

    //注册newFd的读事件
    event.events = EPOLLIN;//注册对应的事件，读
    event.data.fd = newFd;//注册需要监听的描述符添加到结构体里
    ret = epoll_ctl(epfd,EPOLL_CTL_ADD,newFd,&event);
    //参数：epoll句柄，动作（注册新fd到epfd），需要监听的文件描述符，event

    ERROR_CHECK(ret,-1,"epoll_ctl");


    char buf[1024]={0};
    //表示select返回的就绪描述符的数量
    int readyNum=0;

    while(1)
    {
        //最后一个参数填-1，代表永久等待
        //
        readyNum = epoll_wait(epfd,evts,2,-1);
        //描述符就绪的时候，会把对应的event结构体拿到evts中
        //若有多个文件描述符就绪，会分别把对应的event结构体拿到evts[0]和evts[1]
        //readyNum为就绪的文件描述符的数量
        //evts不必每次清空，因为每次while(1)会重新覆盖
        for(int i=0;i<readyNum;i++)
        {
            //判断就绪的文件描述符是不是标准输入
            if(evts[i].data.fd == STDIN_FILENO)
            {
                bzero(buf,sizeof(buf));
                read(STDIN_FILENO,buf,sizeof(buf));
                //-1表示最后的\n不发送
                send(newFd,buf,strlen(buf)-1,0);
            }
            if(evts[i].data.fd == newFd)
            {
                bzero(buf,sizeof(buf));
                //客户端断开的时候，内核会把newFd标记为可读
                //epoll就会一直检测到newFd是可读的
                //就会一直进入到这个分支
                ret = recv(newFd,buf,sizeof(buf),0);
                //对端断开的退出机制
                //当对方断开，recv的返回值为0
                if(ret == 0)
                {
                    printf("byebye\n");
                    goto end;
                }
                printf("%s\n",buf);
            }
        }

    }
end:

    close(newFd);
    close(sfd);

}

