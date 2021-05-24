#include<func.h>
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2);
    int fdr=open(argv[1],O_RDONLY);
    fd_set rdset;//rdset读集合，用来监听多个用来读的文件描述符
    FD_ZERO(&rdset);//清空rdset
    FD_SET(fdr,&rdset);//把fdr加入监听
    FD_SET(STDIN_FILENO,&rdset);//把标准输入加入监听
    char buf[128]={0};
    select(fdr+1,&rdset,NULL,NULL,NULL);
    if(FD_ISSET(fdr,&rdset));
    {//如果fdr有消息过来
        printf("message from pipe\n");
        read(fdr,buf,sizeof(buf));
        printf("buf=%s\n",buf);
    }
    if(FD_ISSET(STDIN_FILENO,&rdset))
    {//如果标准输入发来内容
        printf("message from stdin\n");
        read(STDIN_FILENO,buf,sizeof(buf));
        printf("buf=%s\n",buf);
    }
    return 0;
}
