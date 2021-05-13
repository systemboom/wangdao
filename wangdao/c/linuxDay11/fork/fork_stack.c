#include <func.h>

int main()
{
    pid_t pid;
    int iStack=3;

    pid= fork();
    if(pid>0)
    {
        printf("i am parent childpid=%d,pid=%d\n",pid,getpid());
        printf("istack=%d\n",iStack);
        iStack+=3;
        printf("istack=%d\n",iStack);
        return 0;
    }
    else{
        printf("i am child pid=%d,parent pid=%d\n",pid,getppid());
        printf("istack=%d\n",iStack);
        return 0;
    }
 
}

