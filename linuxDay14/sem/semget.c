#include<func.h>

int main()
{
    int semArrID=semget(1000,1,IPC_CREAT|0600);
    //semArrID表示信号量数组
    ERROR_CHECK(semArrID,-1,"semget");
    
    return 0;
}
