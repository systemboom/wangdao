#include <func.h>

int main(int argc, char* argv[])
{
    struct hostent* p;
    p = gethostbyname(argv[1]);//这个函数需要联网,把域名解析出来
    if(p == NULL)
    {
        printf("gethostbyname error\n");
        return -1;
    }

    printf("%s\n",p->h_name);//打印正式主机名

    for(int i=0;p->h_aliases[i] != NULL;i++)//打印主机别名
    {
        printf("%s\n",p->h_aliases[i]);//用[]变为一级指针(char*)
    }

    printf("type=%d\n",p->h_addrtype);//打印IP地址类型
    printf("length=%d\n",p->h_length);//打印IP地址字节长度


    char buf[128]={0};
    for(int i=0;p->h_addr_list[i] != NULL;i++)//打印主机的IP地址列表
    {
        bzero(buf,sizeof(buf));
        inet_ntop(p->h_addrtype,p->h_addr_list[i],buf,sizeof(buf));
        //将网络字节序 转化为 主机字节序
        //参数为：IP类型，IP地址，传出参数buf，buf大小
        printf("ip=%s\n",buf);
    }
}

