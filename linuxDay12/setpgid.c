
#include <func.h>

int main()
{
    pid_t pid;
    pid= fork();
    if(pid>0)
    {
        printf("i am parent childpid=%d,pid=%d\n",pid,getpid());
        printf("pgid=%d\n",getpgid(0));
        while(1);
    }
    else{
        /* sleep(2); */
        setpgid(0,0);
        printf("pgid=%d\n",getpgid(0));
        printf("i am child pid=%d,parent pid=%d\n",pid,getppid());
        while(1);
    }

    printf("end\n");
    return 0; 
}
