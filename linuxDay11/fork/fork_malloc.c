#include <func.h>

int main()
{
    pid_t pid;
    char *p = (char*)malloc(20);
    strcpy(p,"hello");

    pid= fork();
    if(pid>0)
    {
        printf("i am parent childpid=%d,pid=%d\n",pid,getpid());
        printf("p=%s\n",p);
        p[0]='H';
        printf("p=%s\n",p);
        return 0;
    }
    else{
        printf("i am child pid=%d,parent pid=%d\n",pid,getppid());
        printf("p=%s\n",p);
        return 0;
    }
 
}
