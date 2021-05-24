#define _GNU_SOURCE
#include <func.h>

#define MAXFDNUM 10

int recvCycle(int,void*,int);
int main(int argc, char* argv[])
{

    ARGS_CHECK(argc,3);
    int fds[2]={0};
    pipe(fds);//创建管道

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
    //相当于接到了火车头
    size_t fileSize=0;
    recvCycle(sfd,&dataLen,4);
    recvCycle(sfd,&fileSize,dataLen);
    printf("fileSize=%ld\n",fileSize);

    struct timeval start,end;
    gettimeofday(&start,NULL);
    size_t recvSize = 0;

    while(recvSize<fileSize)
    {
        ret = splice(sfd,NULL,fds[1],NULL,65535,SPLICE_F_MORE);
        //将sfd的数据传到管道写端fds[1]
        //pipe创建的管道写端为fds[1]
        //SPLICE_F_MOVE表示提示内核应当用move，而不是copy，但内核不一定接受这样做，linux2.6以上
        //版本该参数没有意义
        //SPLICE_F_MOVE表示后面还有更多的数据到来，一般填这个

        ERROR_CHECK(ret,-1,"splice1");
        ret = splice(fds[0],NULL,fd,NULL,ret,SPLICE_F_MORE);
        //将管道中的数据传到fd
        ERROR_CHECK(ret,-1,"splice2");
        recvSize+=ret;
    }

    printf("100.00%%\n");
    gettimeofday(&end,NULL);

    printf("cost time=%ld\n",((end.tv_sec-start.tv_sec)*1000000)+end.tv_usec-start.tv_usec);
    close(fd);
    close(sfd);
    return 0;
}

