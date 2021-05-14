#include<func.h>
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2);
    int fd;
    fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    printf("fd=%d\n",fd);
    int fd1;
    fd1=dup(fd);
    printf("fd1=%d\n",fd1);
    char buf[128]={0};
    int ret;
    ret=read(fd,buf,5);
    ERROR_CHECK(ret,-1,"read");
    printf("read from fd %s\n",buf);
    
    memset(buf,0,sizeof(buf));//每次读取内容的时候，务必清空buf
    
    ret=read(fd1,buf,5);
    ERROR_CHECK(ret,-1,"read");
    printf("read from fd1 %s\n",buf);
    close(fd);
    close(fd1);
    return 0;
}

