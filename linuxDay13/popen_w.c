#include <func.h>

int main()
{
    FILE *fp;
    //“w”的方式启动新的进程
    //fwrite写给文件流fp的数据会传递给新进程的标准输入
    //read进程可以读标准输入读到fwrite写进来的hello read
    fp = popen("./read","w");
    fwrite("hello read",sizeof(char),10,fp);

    pclose(fp);
    return 0;
}

