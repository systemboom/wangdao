#include <func.h>

int main(int argc,char *argv[])
{
    printf("i am print\n");
    for(int i=0;i<argc;i++)
    {
        printf("argv[%d]=%s\n",i,argv[i]);
    }
    while(1);
    return 0;
}

