#include <stdio.h>
void print(char *str){
   puts("this is print");
    puts(str);
}
int main(int argc,char *argv[]){
    for(int i=0;i<argc;++i){
        print(argv[i]);
    }
    printf("Hello world\n");
    return 0;
}
