#include <func.h>

int main()
{
    printf("pid=%d,uid=%d,gid=%d,euid=%d,egid=%d\n",
           getpid(),getuid(),getgid(),geteuid(),getegid());
    int fd=open("file",O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    write(fd,"hello",5);
    close(fd);
    return 0;

}
