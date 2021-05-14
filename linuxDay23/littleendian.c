#include <stdio.h>

int main()
{
    short port=0x1234;
    char *p=(char*)&port;

    if(*p==0x12)
    {
        printf("big endian\n");
        printf("%x\n",*p);
    }
    else if(*p==0x34)
    {
        printf("little endian\n");
        printf("%x\n",*p);
    }
    return 0;
}

