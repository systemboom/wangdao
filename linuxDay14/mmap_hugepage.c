#include <func.h>

#define MAP_HUGE_2MB 1<<21

int main()
{
    int fd = open("./huge/file",O_RDWR|0666);
    ERROR_CHECK(fd,-1,"open");

    ftruncate(fd,1<<22);
    char *p = (char*)mmap(NULL,1<<22,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_HUGETLB|MAP_HUGE_2MB,fd,0);
    ERROR_CHECK(p,(char*)-1,"mmap");

    strcpy(p,"hello hugepage\n");
    munmap(p,10);

    return 0;
 
}

