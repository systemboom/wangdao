#include <func.h>

int main()
{
    FILE *fp;

    fp = popen("./print","r");
    char buf[64]={0};
    fread(buf,sizeof(char),sizeof(buf),fp);
    printf("buf=%s\n",buf);

    return 0;
}

