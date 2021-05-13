#include <stdio.h>
void print(char *str){
   puts("this is print");
    puts(str);
}
int main(){
    int i=10;
    int j=11;
    printf("j=%d,i=%d\n",j++,++i);
    char *p="how are you";
    char str[20]="how are you";
    print(p);
    print(str);
    printf("Hello world\n");
    return 0;
}

