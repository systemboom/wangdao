#include <func.h>

int main()
{

    if(fork())
    {
        printf("i am parent pid=%d\n",getpid());
        while(1);
        return 0;
    }
    else{
        printf("i am child ppid=%d\n",getppid());
        return 0;
    }
 
}

