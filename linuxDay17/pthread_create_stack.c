#include <func.h>

void *threadFunc(void *p)
{
    printf("child thread create val=%d\n",*(int *)p);
    //因为p是void*类型的，而传入参数是int型，所以要先做一个类型转换
    //先转换成int*，再对int*类型做解引用，得到int型的值
    pthread_exit(NULL);
}

int main()
{
    pthread_t thid;

    int iStack=3;

    int ret;
    ret = pthread_create(&thid,NULL,threadFunc,&iStack);
    THREAD_ERRORCHECK(ret,"pthread_create");
    
    printf("ret=%d\n",ret);
    printf("main thread after create\n");
    pthread_join(thid,NULL);
}

