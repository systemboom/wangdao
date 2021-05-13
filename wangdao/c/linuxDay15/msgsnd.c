#include <func.h>

struct msgbuf{
    long mtype;
    char mtext[64];
};

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        printf("args error\n");
        return -1;
    }
    int msgid = msgget(1000,IPC_CREAT|0600);
    //创建一个消息队列
    ERROR_CHECK(msgid,-1,"msgget");

    struct msgbuf msg;//消息体
    memset(&msg,0,sizeof(msg));
    //对msgbuf初始化

    msg.mtype = atoi(argv[1]);
    //mtype必须是个大于0的正整数
    strcpy(msg.mtext,argv[2]);
    int ret;
    ret = msgsnd(msgid,&msg,strlen(msg.mtext),0);
    //msgsnd参数：消息队列编号、消息结构体地址、消息体mtest[]大小、msgflg
    ERROR_CHECK(ret,-1,"msgsnd");
    
    return 0;
}
