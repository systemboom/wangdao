#include <func.h>

int main()
{
    printf("pid=%d,uid=%d,gid=%d,euid=%d,egid=%d\n",
           getpid(),getuid(),getgid(),geteuid(),getegid());
    while(1);
    return 0;
 
}

