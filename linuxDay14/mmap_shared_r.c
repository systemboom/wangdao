#include <func.h>

int main()
{
    int fd = open("file",O_RDWR|0666);
    ERROR_CHECK(fd,-1,"open");
    
    ftruncate(fd,1024);
    //mmap要求文件大小固定
    char *p = (char*)mmap(NULL,10,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    //PROT_READ|PROT_WRITE可读可写
    //MAP_SHARED共享这段映射，对其他进程可见，可以实现共享内存的效果
    ERROR_CHECK(p,(char*)-1,"mmap");

    printf("p=%s\n",p);
    munmap(p,10);
    //解除映射
    return 0;
 
}

