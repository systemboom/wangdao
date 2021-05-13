#include "iostream"
using std::cout;
using std::endl;

class BankWorker{
public:
    virtual void doBusiness()=0;
};

class SaveBankWorder
:public BankWorker{
public:
    void doBusiness() override{
        cout<<"办理存款业务"<<endl;
    }
};

class PayBankWorder
:public BankWorker{
public:
    void doBusiness() override{
        cout<<"办理支付业务"<<endl;
    }
};

class TransBankWorder
:public BankWorker{
public:
    void doBusiness() override{
        cout<<"办理转账业务"<<endl;
    }
};
void doBusiness(BankWorker * worker){
    worker->doBusiness();
}

void test0(){
    BankWorker * saveWorker = new SaveBankWorder();
    BankWorker * payWorker  = new PayBankWorder();
    BankWorker * transWorker = new TransBankWorder();
    doBusiness(saveWorker);
    doBusiness(payWorker);
    doBusiness(transWorker);
}
int main()
{
    test0();
    return 0;
}

