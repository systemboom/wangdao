#include "process_pool.h"

#define FILENAME "file"

int transFile(int sfd)
{
    int fd = open(FILENAME,O_RDWR);
    ERROR_CHECK(fd,-1,"open");

    train_t train;
    bzero(&train,sizeof(train));
    //发送文件名
    train.dataLen = strlen(FILENAME);
    strcpy(train.buf,FILENAME);
    //要发送的是火车头长度和车厢的数据的长度
    send(sfd,&train,4+train.dataLen,0);

    //发送文件大小
    //文件大小就是整个大火车的火车头
    struct stat filestat;
    bzero(&filestat,sizeof(filestat));
    fstat(fd,&filestat);
    printf("fileSize=%ld\n",filestat.st_size);
    train.dataLen= sizeof(filestat.st_size);
    memcpy(train.buf,&filestat.st_size,sizeof(filestat.st_size));
    send(sfd,&train,4+train.dataLen,0);

    off_t sendSize=0;
    //off_t为4个字节

    //一次性发送一辆大火车，把整个文件发送过去
    //车厢就是整个文件内容，火车头记录的值是文件大小
    //int ret = sendfile(sfd,fd,NULL,filestat.st_size);
    //将数据从fd传输到sfd
    //ERROR_CHECK(ret,-1,"sendfile");

    while(1)
    {
        int ret = sendfile(sfd,fd,NULL,filestat.st_size);
        ERROR_CHECK(ret,-1,"sendfile");
        sendSize+=ret;
        if(sendSize == filestat.st_size)
            break;
        //如果发送的字节数等于文件字节数，退出循环
    }

    return 0;

}

