/*************************************************************************
  > File Name: orphan.c
  > Author: Name
  > Mail: Name@163.com 
  > Created Time: 2020-04-17 14:57:59
 ************************************************************************/

#include <func.h>
int func1()
{
    exit(2);
}

int func()
{
    printf("ready to exit\n");
    /* func1(); */
    printf("ready to exit\n");
    exit(0);
}

int main()
{
    if(fork())
    {
        printf("i am parent pid=%d\n",getpid());
        int status=0;
        pid_t childpid;
        childpid = wait(&status);
        printf("child exit\n");
        printf("childpid = %d\n",childpid);
        return 0;
    }
    else{
        printf("i am child ppid=%d\n",getppid());
        sleep(5);
        func();
        printf("after func\n");
        return 3;
        //exit(3);
    }
}

