#include <func.h>

int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2);
    int fdr=open(argv[1],O_RDONLY);//读
    ERROR_CHECK(fdr,-1,"open");
    printf("fdr=%d\n",fdr);
    char buf[128]={0};
    read(fdr,buf,sizeof(buf));
    printf("buf=%s\n",buf);
    return 0;
}

