#include <func.h>

int main(int argc,char* argv[])
{
    int ret;
    ret = kill(atoi(argv[1]),2);
    ERROR_CHECK(ret,-1,"kill");
 
}

