#include<func.h>
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2);
    int fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    FILE *fp=fdopen(fd,"rb+");
    ERROR_CHECK(fp,NULL,"fdopen");
    char buf[128]={0};
    printf("before close,fd=%d\n",fd);
    
    close(fd);
    
    printf("after close,fd=%d\n",fd);
    char *p=fgets(buf,sizeof(buf),fp);//从fp中读取一行到buf中
    ERROR_CHECK(p,NULL,"fgets");
    printf("buf=%s\n",buf);
    return 0;
}

