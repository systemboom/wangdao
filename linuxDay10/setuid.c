#include <func.h>
 
int main()
{
    printf("pid=%d,uid=%d,gid=%d\n",getpid(),getuid(),getgid());
    int ret = setuid(1001);
    ERROR_CHECK(ret,-1,"setuid");
    printf("pid=%d,uid=%d,gid=%d\n",getpid(),getuid(),getgid());
    printf("euid=%d\n",geteuid());
    while(1);
    return 0;
 
}

