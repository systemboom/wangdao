#include<func.h>
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,1);
    int stdin_fd=fileno(stdin);
    printf("stdin_fd=%d\n",stdin_fd);
    int stdout_fd=fileno(stdout);
    printf("stdout_fd=%d\n",stdout_fd);
    int stderr_fd=fileno(stderr);
    printf("stderr_fd=%d\n",stderr_fd);
    return 0;
}

