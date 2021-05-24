#include <func.h>

int main()
{
    pid_t pid = fork();
    if(pid)
    {
        printf("i am parent pid=%d\n",getpid());
        int status=0;
        pid_t childpid;
        //waitpid如果第三个参数是WNOHANG，父进程不会阻塞，
        //如果已经有子进程退出，还是会拿到退出码
        //如果子进程没有退出，父进程不在等待，
        //waitpid直接返回。
        sleep(1);
        childpid = waitpid(pid,&status,WNOHANG);

        //如果waitpid的第一个参数填写的是-1
        //代表等待任何一个子进程，效果跟wait是一样的
        //childpid = waitpid(-1,&status,0);效果等同于wait(&status);
        //wait(NULL)不拿子进程的退出码
        printf("i am parent :child exit\n");
        printf("childpid = %d\n",childpid);
        return 0;
    }
    else{
        printf("i am child ppid=%d\n",getppid());
        sleep(3);
        printf("i am child: child exit\n");
        exit(0);
    }
}
