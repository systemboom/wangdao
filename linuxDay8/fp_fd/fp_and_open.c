 #include<func.h>
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2);
    FILE *fp=fopen(argv[1],"rb+");//使用FILE打开文件，rb+模式若打开的文件不存在，则会报错
    char str[]="from read\n";
    write(3,str,strlen(str));//使用文件描述符进行读写
    fclose(fp);
    return 0;
}

