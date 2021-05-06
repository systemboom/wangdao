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

    int ret=0;
    //发送文件大小
    struct stat filestat;
    bzero(&filestat,sizeof(filestat));
    fstat(fd,&filestat);
    //获取文件权限，文件权限会被吸入filestat中

    printf("fileSize=%ld\n",filestat.st_size);
    train.dataLen= sizeof(filestat.st_size);
    memcpy(train.buf,&filestat.st_size,sizeof(filestat.st_size));
    send(sfd,&train,4+train.dataLen,0);

    char *pMap = (char*)mmap(NULL,filestat.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    //mmap的返回值是void*，我们要转换成char*类型

    ERROR_CHECK(pMap,(char*)-1,"mmap");
    size_t sendSize=0;


    //发送文件内容
    while(filestat.st_size - sendSize>=1000)
    {
        train.dataLen = sizeof(train.buf);
        //每次只能拷贝train.buf个字节大小，所以要循环拷贝  
        memcpy(&train.buf,pMap+sendSize,train.dataLen);
        //每次从pMap+sendSize的位置拷贝datalen个字节到buf中
        
        ret=send(sfd,&train,4+train.dataLen,0);
        if(-1==ret)
        {//表示对端断开
            return -1;
        }
        //在while1里会把文件内容发送出去，当读到文件末尾的时候，
        //read返回值等于0，跳出while循环
        sendSize+=train.dataLen;
    }

    //发送最后一辆装有文件内容的火车，发送剩余的不足1000的文件长度
    if(filestat.st_size - sendSize>0)
    {
        train.dataLen = filestat.st_size - sendSize;
        memcpy(&train.buf,pMap+sendSize,train.dataLen);
        send(sfd,&train,4+train.dataLen,0);
    }
    printf("sendSize=%ld\n",sendSize+train.dataLen);

    //发送文件结束标志
    train.dataLen = 0;
    send(sfd,&train,4+train.dataLen,0);

    return 0;

}

