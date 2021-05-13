#include <func.h>
int main(int argc, char *argv[])
{
    ARGS_CHECK(argc,3);//chat1 1.pipe 2.pipe
    int fdr = open(argv[1], O_RDONLY);
    int fdw = open(argv[2], O_WRONLY);
    puts("qq1");
    char buf[128] = {0};
    fd_set rdset;
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
    }
    close(fdr);
    close(fdw);
    return 0;
}

