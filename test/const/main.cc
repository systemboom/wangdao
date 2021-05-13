#include<cstdio>
int main()
{

    const int i = 0;         //定义常量i
    int *j = (int *) &i;   //看到这里能对i进行取值，判断i必然后自己的内存空间
    *j = 1;                  //对j指向的内存进行修改
   
    int k;
    k=i;
    printf("0x%p\n0x%p\n%d\n%d\n",&i,j,i,*j); //观看实验效果
    
    printf("%d\n",*(&i));

    printf("%d\n",k);
    return 0;
}
