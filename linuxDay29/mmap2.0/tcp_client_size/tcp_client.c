#include <func.h>
#define MAXFDNUM 10

int recvCycle(int,void*,int);
int main(int argc, char* argv[])
{

    ARGS_CHECK(argc,3);

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

    char* pMap = (char*)mmap(NULL,fileSize,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    //建立pMap与file的映射，后面直接recv接收到file里
    //要注意的是，我们用open创建的新文件没有大小，没有文件大小的话，mmap映射的时候，不会真的写
    //到文件里，调用mmap的时候，不会真的写回到磁盘上（因为文件没有大小），所以
    //我们需要ftruncate设置文件大小
    ERROR_CHECK(pMap,(char*)-1,"mmap");

    ret = ftruncate(fd,fileSize);
    //ftruncate可以把文件大小设置成固定大小。

    recvCycle(sfd,pMap,fileSize);

    munmap(pMap,fileSize);//解除映射
    printf("100.00%%\n");
    gettimeofday(&end,NULL);

    printf("cost time=%ld\n",((end.tv_sec-start.tv_sec)*1000000)+end.tv_usec-start.tv_usec);
    close(fd);
    close(sfd);
    return 0;
}

