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
    close(fd);
    char buf[128]={0};
    int ret=read(fd1,buf,sizeof(buf));
    ERROR_CHECK(fd,-1,"read");
    puts(buf);
    return 0;
}

