#include <func.h>

struct msgbuf{
    long mtype;
    char mtext[64];
};

int main(int argc, char *argv[])
{

    int msgid = msgget(1000,IPC_CREAT|0600); 
    ERROR_CHECK(msgid,-1,"msgget");

    struct msgbuf msg;
    memset(&msg,0,sizeof(msg));
    
    int ret;
    /* ret = msgrcv(msgid,&msg,sizeof(msg.mtext),atoi(argv[1]),0); */
    //第四个参数mtype为0的时候，会按照整个队列的接收顺序读出来
    //当第四个参数mtype小于0的时候，接受的是小于|mtype|的最小的类型第一个消息
    ret = msgrcv(msgid,&msg,sizeof(msg.mtext),-2,0);
    ERROR_CHECK(ret,-1,"msgsnd");

    printf("type=%ld,text=%s\n",msg.mtype,msg.mtext);

    return 0;
}

