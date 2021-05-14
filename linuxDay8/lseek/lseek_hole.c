#include<func.h>
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2);
    int fd;
    fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    int ret=lseek(fd,1024,SEEK_SET);
    //这里会形成一个文件空洞。因为前面的位置不会被修改，读写位置从1024开始
    printf("pos=%d\n",ret);
    char c='H';
    write(fd,&c,sizeof(char));
    printf("fd=%d\n",fd);
    close(fd);
    return 0;
}

