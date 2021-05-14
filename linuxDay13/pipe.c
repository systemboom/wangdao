#include <func.h>

int main()
{
    int fds[2]={0};
    int ret = pipe(fds);
    ERROR_CHECK(ret,-1,"pipe");
    printf("fds[0]=%d,fds[1]=%d\n",fds[0],fds[1]);

    char buf[64]={0};
    write(fds[1],"hello",5);
    read(fds[0],buf,sizeof(buf));
    printf("buf=%s\n",buf);

    return 0;
 
}
