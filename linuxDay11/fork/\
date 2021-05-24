#include <func.h>

int main()
{
    pid_t pid;
    //先open，父进程偏移，子进程写文件
    //此时，父子进程是共享同一个文件对象
    //因为内核fork的时候对文件采用的是dup机制
    //同一个文件对象，父进程偏移之后，子进程再写，
    //就会从偏移后的第6个字节出开始写文件
    //helloworld就会变成hellonihao
    int fd = open("file",O_RDWR);
    pid= fork();
    if(pid>0)
    {
        printf("i am parent childpid=%d,pid=%d\n",pid,getpid());
        lseek(fd,5,SEEK_SET);
        close(fd);
        return 0;
    }
    else{
        /* int fd = open("file",O_RDWR); */
        printf("i am child pid=%d,parent pid=%d\n",pid,getppid());
        write(fd,"nihao",5);
        close(fd);
        return 0;
    }
 
}

