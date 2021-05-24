#include <func.h>
#define SHM_HUGE_2MB 1<<21
//SHM_HUGE_2MB需要自己定义，左移21位，即2M
int main()
{
    int shmid= shmget(1000,1<<22,IPC_CREAT|SHM_HUGETLB|SHM_HUGE_2MB|0600);
    ERROR_CHECK(shmid,-1,"shmid");
    printf("shmid=%d\n",shmid);
    int *p = (int*)shmat(shmid,NULL,0);
    ERROR_CHECK(p,(int*)-1,"shmat");
    p[0]=10;
    while(1);
    return 0;
}

