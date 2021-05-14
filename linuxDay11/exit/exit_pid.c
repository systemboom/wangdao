#include <func.h>

int main()
{
    pid_t pid = fork();
    if(pid)
    {
        printf("i am parent pid=%d\n",getpid());
        int status=0;
        pid_t childpid;
        childpid = waitpid(pid,&status,0);
        printf("child exit\n");
        printf("childpid = %d\n",childpid);
        return 0;
    }
    else{
        printf("i am child ppid=%d\n",getppid());
        sleep(3);
        exit(3);
    }
}

