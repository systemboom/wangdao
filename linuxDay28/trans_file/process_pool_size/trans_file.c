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
    struct stat filestat;
    bzero(&filestat,sizeof(filestat));
    fstat(fd,&filestat);
    printf("fileSize=%ld\n",filestat.st_size);

    train.dataLen= sizeof(filestat.st_size);
    //因为发送的车厢内容是”文件大小“，所以火车头填的是“文件大小”的字节大小
    memcpy(train.buf,&filestat.st_size,sizeof(filestat.st_size));
    send(sfd,&train,4+train.dataLen,0);


    //发送文件内容
    while((train.dataLen = read(fd,train.buf,sizeof(train.buf))))
    {
        //在while1里会把文件内容发送出去，当读到文件末尾的时候，
        //read返回值等于0，跳出while循环
        send(sfd,&train,4+train.dataLen,0);
    }

    //发送文件结束标志
    send(sfd,&train,4+train.dataLen,0);

    return 0;

}

