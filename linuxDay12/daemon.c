#include <func.h>

int main()
{

    //父进程退出，让子进程变成孤儿进程
    if(fork())
        exit(0);

    setsid();//成立一个新的会话
    chdir("/");//把当前工作目录改成根目录
    umask(0);//把文件权限掩码改成0

    for(int i=0;i<3;i++)//因为没有打开其他文件，所以只关掉012就可以了
    {
        close(i);
    }
 
    while(1)
    {
        sleep(1);
    }
    return 0;
}

