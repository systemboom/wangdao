#include <func.h>

char buf[200];

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
    char *pTime = ctime_r(&now,buf1);
    printf("child addr %p\n",pTime);
    printf("child addr %p\n",buf1);
    printf("child now time = %s\n",pTime);
    sleep(3);
    printf("child now time = %s\n",pTime);

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
    time_t now;
    time(&now);
    char buf1[64]={0};
    char *pTime = ctime_r(&now,buf1);
    printf("main addr %p\n",pTime);
    printf("main now time = %s\n",pTime);

    pthread_join(thid,NULL);
}

