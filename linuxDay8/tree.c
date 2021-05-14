#include<func.h>
int DFSprint(char *path,int width) //目录、宽度
{
    DIR *dir=opendir(path);//dir先获取目录下所有孩子
    ERROR_CHECK(dir,NULL,"opendir");

    struct dirent *pdirent;
    char buf[1024]={0};
    while((pdirent=readdir(dir)))
    {
        if(strcmp(pdirent->d_name,".")==0||strcmp(pdirent->d_name,"..")==0)
        {//避免访问.本级目录和..上级目录，因为会造成死循环
            continue;
        }
        printf("%*s%s\n",width,"",pdirent->d_name);//实现可变宽度的空格数量
        sprintf(buf,"%s%s%s",path,"/",pdirent->d_name);//实现路径的拼接
        if(4==pdirent->d_type)//d_type=4说明是一个目录
        {//如果是目录。则继续向下DFS
            DFSprint(buf,width+4);
        }
    }
    closedir(dir);
    return 0;
}
int main(int argc,char *argv[]){
   ARGS_CHECK(argc,2); 
   puts(argv[1]);
   DFSprint(argv[1],0);
   return 0;
}

