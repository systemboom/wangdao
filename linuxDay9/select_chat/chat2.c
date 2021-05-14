#include<func.h>
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,3);
    int fdw=open(argv[1],O_WRONLY);
    int fdr=open(argv[2],O_RDONLY);
    //chat2这里要反过，因为只有读端和写端都建立了才能继续运行
    puts("chat2");
    fd_set rdset;//rdset读集合，用来监听多个用来读的文件描述符
    char buf[128]={0};
    while(1)
    {
        FD_ZERO(&rdset);
        FD_SET(fdr,&rdset);
        FD_SET(STDIN_FILENO,&rdset);
        select(fdr+1, &rdset,NULL,NULL,NULL);
        if(FD_ISSET(fdr,&rdset)){
            puts("pipe");
            memset(buf,0,128);
            read(fdr,buf,128);
            puts(buf);
        }
        if(FD_ISSET(STDIN_FILENO,&rdset)){
            puts("stdin");
            memset(buf,0,128);
            read(STDIN_FILENO,buf,128);
            write(fdw,buf,strlen(buf));
        }
        //chat2这里要反过，
        /* FD_ZERO(&rdset);//清空rdset */
        /* FD_SET(fdr,&rdset);//把fdr加入监听 */
        /* FD_SET(STDIN_FILENO,&rdset);//把标准输入加入监听 */
        /* select(fdr+1,&rdset,NULL,NULL,NULL); */
        /* if(FD_ISSET(fdr,&rdset)); */
        /* {//如果fdr有消息过来 */
        /*     printf("message from pipe\n"); */
        /*     memset(buf,0,sizeof(buf)); */
        /*     read(fdr,buf,sizeof(buf)); */
        /*     printf("buf=%s\n",buf); */
        /* } */
        /* if(FD_ISSET(STDIN_FILENO,&rdset)) */
        /* {//如果标准输入发来内容 */
        /*     printf("message from stdin\n"); */
        /*     memset(buf,0,sizeof(buf)); */
        /*     read(STDIN_FILENO,buf,sizeof(buf)); */
        /*     printf("buf=%s\n",buf); */
        /*     write(fdw,buf,strlen(buf)-1);//避免write进回车，所以减-1 */

    }
    return 0;
}
