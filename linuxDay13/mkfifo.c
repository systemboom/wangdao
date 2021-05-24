#include <func.h>

int main(int argc,char* argv[])
{
    int ret = mkfifo(argv[1],0666);
    ERROR_CHECK(ret,-1,"mkfifo");
    return 0;
}

