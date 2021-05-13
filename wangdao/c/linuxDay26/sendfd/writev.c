#include <func.h>

int main()
{
    int fd = open("file1",O_RDWR|O_CREAT);
    
    struct iovec iov[2];
    char buf[64]="hello";
    char buf2[64]="world";
    
    iov[0].iov_base=buf;
    iov[0].iov_len = strlen(buf);

    iov[1].iov_base=buf2;
    iov[1].iov_len = strlen(buf2);

    //writev对应sendmsg  
    //write 对应的send和sendto
    int ret = writev(fd,iov,2);
    printf("ret=%d\n",ret);

 
}
