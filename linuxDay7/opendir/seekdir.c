#include<func.h>
int main(int argc,char *argv[])
{
    ARGS_CHECK(argc,2);
    DIR *dir;//指向目录流的指针
    dir=opendir(argv[1]);
    struct dirent *p;
    long off;
    while((p=readdir(dir)))
    {
        printf("ino=%ld,len=%d,type=%d,filename=%s\n",p->d_ino,p->d_reclen,p->d_type,p->d_name);
        if(0==strcmp(p->d_name,"seekdir.c"))
        {
            off=telldir(dir);//上标记
        }
    }
    //p指向了NULL
    seekdir(dir,off);//回到上标记的地方
    puts("----------------------");
    p=readdir(dir);
    ERROR_CHECK(p,NULL,"readdir");
    printf("ino=%ld,len=%d,type=%d,filename=%s\n",p->d_ino,p->d_reclen,p->d_type,p->d_name);
    closedir(dir);
    return 0;
}

