#include <stdio.h>
int func(int *i){
    ++(*i);
    func(i);
    return 0;
}
int main()
{
    int i=0;
    func(&i);
    printf("Hello world\n");
    return 0;
}

