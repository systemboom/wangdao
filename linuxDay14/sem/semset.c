#include <func.h>

int main()
{
    int semArrId = semget(1000,3,IPC_CREAT|0600); 
    ERROR_CHECK(semArrId,-1,"semget");

    unsigned short arr[3]={3,5,7};
    //设置信号量初值
    int ret;
    ret=semctl(semArrId,0,SETALL,arr);
    ERROR_CHECK(ret,-1,"semctl");

    memset(arr,0,sizeof(arr));
    ret=semctl(semArrId,0,GETALL,arr);
    //将信号量数组传入arr
    ERROR_CHECK(ret,-1,"semctl");
    printf("arr[0]=%d,arr[1]=%d,arr[2]=%d\n",arr[0],arr[1],arr[2]);

    return 0; 
}
