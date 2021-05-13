#include <func.h>

int setNonblock(int fd)
{
    int status=0;
    status = fcntl(fd,F_GETFL);
    printf("%x\n",status);
    status = status|O_NONBLOCK;//非阻塞
    printf("%x\n",status);
    fcntl(fd,F_SETFL,status);

    return 0;
}

int main()
{
    setNonblock(0);
    char buf[100]={0};
    int ret=0;
    ret = read(STDIN_FILENO,buf,sizeof(buf)); 
    printf("read ret=%d,buf=%s\n",ret,buf);
}

