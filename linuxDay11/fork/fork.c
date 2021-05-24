#include <func.h>

int main()
{
    pid_t pid;
    pid= fork();
    if(pid>0)
    {
        printf("i am parent childpid=%d,pid=%d\n",pid,getpid());
    }
    else{
        /* sleep(2); */
        printf("i am child pid=%d,parent pid=%d\n",pid,getppid());
    }

    printf("end\n");
    return 0; 
}
