/*************************************************************************
  > File Name: orphan.c
  > Author: Name
  > Mail: Name@163.com 
  > Created Time: 2020-04-17 14:57:59
 ************************************************************************/

#include <func.h>

int func()
{
    printf("ready to exit");
    //_exit不会清理IO缓冲，因此，上面这一句不带\n的打印
    //程序结束时是看不到这一句的
    /* _exit(0); */
    //exit退出时会清理IO缓冲区，
    //所以上面的打印可以看到
    _exit(0);
}

int main()
{
    if(fork())
    {
        printf("i am parent pid=%d\n",getpid());
        wait(NULL);
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

