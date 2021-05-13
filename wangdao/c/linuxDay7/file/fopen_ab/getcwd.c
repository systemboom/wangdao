#include<func.h>

int main(int argc,char *argv[])
{
    /* char buf[128]={0}; */
    /* char *ret=getcwd(buf,sizeof(buf)); */
    /* ERROR_CHECK(ret,NULL,"getcwd"); */
    /* puts(buf); */
    printf("%s\n",getcwd(NULL,0));
    return 0;
}

