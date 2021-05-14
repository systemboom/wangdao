/*************************************************************************
	> File Name: setNonblock.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-05-04 15:10:24
 ************************************************************************/

#include <func.h>

int setNonblock(int fd)
{
    int status=0;
    status = fcntl(fd,F_GETFL);
    /* printf("%x\n",status); */
    status = status|O_NONBLOCK;
    /* printf("%x\n",status); */
    fcntl(fd,F_SETFL,status);

    return 0;
}

