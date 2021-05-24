#include <func.h>

int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2);
    int fdw=open(argv[1],O_WRONLY);//写
    ERROR_CHECK(fdw,-1,"open");
    printf("fdr=%d\n",fdw);
    char buf[]="helloworld";
    write(fdw,buf,strlen(buf));
    printf("buf=%s\n",buf);
    return 0;
}

