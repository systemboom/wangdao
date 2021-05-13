#include<func.h>
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2);
    int fd;
    fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    printf("\n");//因为stdout是行缓冲，一开始要清空缓冲区
    //不清空的话，stdout和屏幕上的内容会不一致
    close(STDOUT_FILENO);
    int fd1=dup(fd);//fd1==1
    printf("fd1=%d\n",fd1);
    printf("can you see me?\n");
    close(fd);
    return 0;
}

