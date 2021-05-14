#include<func.h>
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2);
    int fd;
    //fd=open(argv[1],O_RDWR);
    //fd=open(argv[1],O_RDWR|O_CREAT,0666);
    // fd=open(argv[1],O_RDWR|O_CREAT|O_EXCL,0666);
    fd=open(argv[1],O_RDWR|O_TRUNC);
    ERROR_CHECK(fd,-1,"open");
    printf("fd=%d\n",fd);
    close(fd);
    return 0;
}

