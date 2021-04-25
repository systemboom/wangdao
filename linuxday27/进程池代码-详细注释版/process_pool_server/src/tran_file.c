#include "process_pool.h" 
//对端端开时，第一次send会返回-1，第二次send会受到SIGPIPE信号
//这里的信号处理函数是为了看到信号到来，实际我们检查了send的返回值为-1之后，
//就返回，不会再去send了，因此这里只是测试用的。
void sigFunc(int signum)
{
    printf("%d is coming\n",signum);
}

// 发送文件流程：先发文件名，对端收到文件名之后，打开同名文件。
// 接着把文件内容读到buf中，再通过send发给对端，知道读到文件末尾
// 发完文件后，发送文件结束标志dataLen=0，表示文件发完，不会再发送了
int tranFile(int newFd)
{
    signal(SIGPIPE,sigFunc);
    //小火车的方式发送，避免TCP粘包问题
    train_t train;
    int ret;
    //1.发送文件名
    train.dataLen=strlen(FILENAME);
    strcpy(train.buf,FILENAME);
    send(newFd,&train,4+train.dataLen,0);

    //2.发送文件大小给客户端,文件大小用于打印进度条
    //同时客户端也可以根据文件大小判断是否接收完毕
    struct stat buf;
    int fd=open(FILENAME,O_RDWR);
    fstat(fd,&buf);//获取文件大小
    train.dataLen=sizeof(buf.st_size);
    memcpy(train.buf,&buf.st_size,train.dataLen);//注意要用memcpy
    send(newFd,&train,4+train.dataLen,0);

    //3.发送文件内容，循环读取，read返回值为从文件中读出的字节数，赋值给dataLen
    //dataLen是真正要发送的文件内容的长度，正好作为火车头
    //当读到文件末尾时，read返回0，dataLen=0，就退出循环。
    while((train.dataLen=read(fd,train.buf,sizeof(train.buf))))
    {
        ret=send(newFd,&train,4+train.dataLen,0);
        if(-1==ret)
        {
            return -1;
        }
    }
    //4.发送文件结束标志
    //退出循环后，train.dataLen=0，发4个字节的火车头过去，
    //对方收到火车头后，发现dataLen=0，知道文件发送完毕，退出循环接收。
    send(newFd,&train,4,0);
    return 0;
}

