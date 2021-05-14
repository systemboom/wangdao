#include <func.h>

int main()
{
    short port=0x1234;
    char* pc= (char*)&port;
    /* short nport=htons(port); */
    printf("port=%x\n",port);
    printf("port=%x\n",*pc);
 
    /* printf("nport=%x\n",nport); */
}

