#include <func.h>

int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,3);
    int fdw=open(argv[1],O_WRONLY);
    int fdr=open(argv[2],O_RDONLY);
    printf("I am chat2 fdr=%d fdw=%d\n",fdr,fdw);
    char buf[128]={0};

    while(1)
    {
        memset(buf,0,sizeof(buf));//清空缓冲区
        read(STDIN_FILENO,buf,sizeof(buf));//从键盘读取，以换行结束
        write(fdw,buf,strlen(buf)-1);
        memset(buf,0,sizeof(buf));
        read(fdr,buf,sizeof(buf));//从管道当中读取
        puts(buf);
    }
    return 0;
}

