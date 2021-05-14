#include<func.h>
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2);
    int fd;
    fd=open(argv[1],O_RDWR);
    ERROR_CHECK(fd,-1,"open");
    printf("fd=%d\n",fd);
    char *p=(char*)mmap(NULL,5,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);//申请堆空间
    ERROR_CHECK(fd,-1,"open");//p[0]-p[4],申请了5个大小可访问的空间
    p[5]='\0';//为了方便演示，把p[5]设为'\0'，这样方便演示
    printf("%s\n",p);//读取映射内容
    p[0]='H';//测试文件file1的文件内容为how，看看mmap有没有修改文件内容
    munmap(p,5);//释放堆空间，解除映射
    close(fd);
    return 0;
}

