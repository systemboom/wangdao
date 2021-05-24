#include "process_pool.h"

#define FILENAME "file"

int transFile(int sfd)
{
    int fd = open(FILENAME,O_RDWR);
    ERROR_CHECK(fd,-1,"open");

    train_t train;
    bzero(&train,sizeof(train));

    //发送文件名
    //车头是文件名大小，车厢是文件名
    train.dataLen = strlen(FILENAME);
    strcpy(train.buf,FILENAME);
    //要发送的是火车头长度和车厢的数据的长度
    send(sfd,&train,4+train.dataLen,0);

    //发送文件大小
    //火车头是文件大小的大小，车厢是文件大小
    struct stat filestat;
    bzero(&filestat,sizeof(filestat));
    fstat(fd,&filestat);//用fstat获取文件信息（在这里主要用于获取文件大小）
    printf("fileSize=%ld\n",filestat.st_size);
    train.dataLen= sizeof(filestat.st_size);
    //datalen文件大小
    memcpy(train.buf,&filestat.st_size,sizeof(filestat.st_size));
    send(sfd,&train,4+train.dataLen,0);//发送文件大小

    char *pMap = (char*)mmap(NULL,filestat.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    ERROR_CHECK(pMap,(char*)-1,"mmap");
    size_t sendSize=0;

    //一次性发送一辆大火车，把整个文件发送过去
    //车厢就是整个文件内容，火车头记录的值是文件大小
    send(sfd,pMap,filestat.st_size,0);
    //这里不需要再发送文件结束标志


    return 0;

}

