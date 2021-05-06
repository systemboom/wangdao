/*************************************************************************
	> File Name: recvCycle.c
	> Author: Name
	> Mail: Name@163.com 
	> Created Time: 2020-05-07 15:21:29
 ************************************************************************/

#include <func.h>

//循环接收
int recvCycle(int sfd,void* buf,int recvLen)
{
    char *p = (char*)buf;
    int total=0;
    int ret = 0;
    while(total<recvLen)
    {
        ret = recv(sfd,p+total,recvLen-total,0);
        total+=ret;
    }

    return 0;
}
