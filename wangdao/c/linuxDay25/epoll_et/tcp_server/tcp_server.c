/*************************************************************************
  > File Name: tcp_server.c
  > Author: Name
  > Mail: Name@163.com 
  > Created Time: 2020-04-30 16:15:36
 ************************************************************************/

#include <func.h>

#define MAXFDNUM 10

int setNonblock(int);
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


    //创建epoll句柄
    int epfd = epoll_create(1);
    ERROR_CHECK(epfd,-1,"epoll_create");

    //向epoll里注册需要监听的文件描述符以及对应的事件

    struct epoll_event event,evts[3];
    //先注册标准输入的读事件
    event.events = EPOLLIN;//注册对应的事件
    event.data.fd = STDIN_FILENO;//注册需要监听的描述符添加到结构体里
    ret = epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl");
    int newFd=0;

    //注册sfd的读事件
    event.events = EPOLLIN;//注册对应的事件
    event.data.fd = sfd;//注册需要监听的描述符添加到结构体里
    ret = epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&event);
    ERROR_CHECK(ret,-1,"epoll_ctl");

    char buf[5]={0};
    //表示epoll返回的就绪描述符的数量
    int readyNum=0;

    while(1)
    {
        //最后一个参数填-1，代表永久等待
        //epoll_wait跟select类似，当注册的文件描述符就绪的时候
        //返回就绪的文件描述符的数量
        //第三个参数代表同时就绪的描述符的最大值
        //一般这个值等于evts结构体数组的大小
        readyNum = epoll_wait(epfd,evts,3,-1);
        /* printf("wake up\n"); */
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
            if(evts[i].data.fd == sfd)
            {
                //当有客户端连接的时候，我们接受对方的连接
                //产生新的newFd
                //代表服务器跟客户端的TCP连接
                newFd = accept(sfd,NULL,NULL);
                ERROR_CHECK(newFd,-1,"accept");
                printf("newFd=%d\n",newFd);

                //把newFd设置成非阻塞模式
                setNonblock(newFd);

                //注册newFd的读事件
                event.events = EPOLLIN|EPOLLET;//注册对应的事件,注册为边缘触发的模式
                event.data.fd = newFd;//注册需要监听的描述符添加到结构体里
                ret = epoll_ctl(epfd,EPOLL_CTL_ADD,newFd,&event);
                ERROR_CHECK(ret,-1,"epoll_ctl");

            }
            if(evts[i].data.fd == newFd)
            {
                //循环读newFd的缓冲区，一直到缓冲区中的数据被
                //读空，被读空之后，因为我们设置了非阻塞的属性
                //recv就不会阻塞，会返回-1，我们再打印\n
                //就能看到一句完整的buf
                while(1)
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
                        //解除注册newFd,用EPOLL_CTL_DEL
                        ret = epoll_ctl(epfd,EPOLL_CTL_DEL,newFd,NULL);
                        ERROR_CHECK(ret,-1,"epoll_ctl");
                        close(newFd);
                        break;
                    }
                    //ret == -1时，代表newFd的缓冲区中没有数据可读
                    if(ret == -1)
                    {
                        printf("\n");
                        break;
                    }
                    printf("%s",buf);
                }
            }
        }

    }

    close(newFd);
    close(sfd);

}
