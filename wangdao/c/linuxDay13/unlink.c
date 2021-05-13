#include <func.h>

int main(int argc, char * argv[])
{
    int ret = unlink(argv[1]);
    ERROR_CHECK(ret,-1,"unlink");
    return 0;
}

