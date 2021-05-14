#include <func.h>

int main()
{
    int semArrId = semget(1000,1,IPC_CREAT|0600); 
    ERROR_CHECK(semArrId,-1,"semget");

    int ret;
    ret=semctl(semArrId,0,SETVAL,3);
    //设置信号量数组的下标为0的信号量为3
    ERROR_CHECK(ret,-1,"semctl");

    ret=semctl(semArrId,0,GETVAL);
    //获取信号量数组的所有信号量的值
    //只有一个信号量的时候，返回1，
    //多个信号量的时候，存入semun.array中
    ERROR_CHECK(ret,-1,"semctl");
    printf("ret=%d\n",ret);

    return 0; 
}

