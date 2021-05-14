#include <func.h>

char buf[200];
//全局变量，生存周期是整个进程
int fun(char *pBuf)
{
    strcpy(buf,pBuf);
    return 0;
}

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
}Data_t,*pData_t;

void* threadFunc(void* p)
{
    time_t now;
    time(&now);
    char buf1[64]={0};
    strcpy(buf1,"child 1");

    fun(buf1);
    printf("child buf = %s\n",buf);
    sleep(3);
    printf("child buf = %s\n",buf);

    pthread_exit(NULL);
}

int main()
{
    pthread_t thid;
    Data_t data;
    pthread_mutex_init(&data.mutex,NULL);
    pthread_cond_init(&data.cond,NULL);

    pthread_create(&thid,NULL,threadFunc,&data);
    sleep(1);//表示放票的一个时间间隔

    char buf1[64]={0};
    strcpy(buf1,"main 1");
    fun(buf1);
    printf(" main buf = %s\n",buf);

    pthread_join(thid,NULL);
}

