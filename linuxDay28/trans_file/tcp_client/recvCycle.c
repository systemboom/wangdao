#include <func.h>

//循环接收
int recvCycle(int sfd,void* buf,int recvLen)
{
    char *p = (char*)buf;
    //因为后面需要p+total偏移，偏移大小是根据指针类型确定的，
    //buf是void型，我们需要每次偏移char类型的大小

    int total=0;//记录recv接收的字节数
    int ret = 0;
    while(total<recvLen)
    {
        ret = recv(sfd,p+total,recvLen-total,0);
        //p+total：从p偏移total的位置开始接收，不能像之前一样每次从首地址开始接收
        //recvlen-total：减去已经接收的字节得到还需接收的字节数
        total+=ret;
    }

    return 0;
}

