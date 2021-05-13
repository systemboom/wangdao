#include<iostream>
#include<memory>
using std::unique_ptr;
using std::cout;
using std::endl;

class Calculator{
public:
    virtual int getResult(int,int)=0;
    virtual ~Calculator(){}
};

class PlusCalculator
:public Calculator{
    int getResult(int x,int y)override{
        return x+y;
    }
};

class MinusCalculator
:public Calculator{
public:
    int getResult(int x,int y)override{
        return x-y;
    }
};

class MultiplyCalculator
:public Calculator{
    int getResult(int x,int y)override{
        return x*y;
    }
};

class DivideCalculator
:public Calculator{
    int getResult(int x,int y)override{
        if(y!=0)
            return x/y;
        else{
            cout<<"除数不能为0"<<endl;
            return 1<<31;
        }
    }
};
void test0(){
    int x=100,y=10;

    unique_ptr<Calculator> myCalc1(new PlusCalculator());
    cout<<"x+y="<<myCalc1->getResult(x,y)<<endl; 
    
    unique_ptr<Calculator> myCalc2(new MinusCalculator());
    cout<<"x-y="<<myCalc2->getResult(x,y)<<endl; 

    unique_ptr<Calculator> myCalc4(new MultiplyCalculator());
    cout<<"x*y="<<myCalc4->getResult(x,y)<<endl; 
    
    unique_ptr<Calculator> myCalc5(new DivideCalculator());
    cout<<"x/y="<<myCalc5->getResult(x,y)<<endl; 
}
int main(){
    test0();
    return 0;
}
