#include<func.h>
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2);
    int fdw=open(argv[1],O_WRONLY);
    puts("I am going to sleep");
    sleep(5);//5秒
    puts("wake up");
    write(fdw,"hello",5);
    return 0;
}
