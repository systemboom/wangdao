#include<func.h>
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2);
    int fd;
    fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    printf("\n");//因为stdout是行缓冲，一开始要清空缓冲区
    //不清空的话，stdout和屏幕上的内容会不一致
    dup2(STDOUT_FILENO,100);
    //把屏幕的文件对象复制给100，方便后面重新指回来
    //如果这里使用dup，屏幕close掉就指不回来了
    dup2(fd,STDOUT_FILENO);//让1文件描述符指向fd
    printf("fd=%d\n",fd);
    printf("you can't see me\n");//打印到文件里
    dup2(100,STDOUT_FILENO);
    printf("you can see me\n");//打印到屏幕上
    close(fd);
    return 0;
}

