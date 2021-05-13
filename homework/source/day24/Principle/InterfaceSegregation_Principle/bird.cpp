#include<iostream>
using std::cout;
using std::endl;
#include<memory>
using std::unique_ptr;
class Bird{
public:
    virtual void eat()=0;
    virtual void walk()=0;
    virtual void chirp()=0;
    virtual ~Bird(){}
};
class FlyingBird
:public Bird{
public:
    virtual void fly()=0;
};

class Crow
:public FlyingBird{
public: 
    void eat()override {
        cout<<"乌鸦喝水"<<endl;
    }
    void walk()override{
        cout<<"乌鸦散步"<<endl;
    }
    void chirp()override{
        cout<<"乌鸦蹦蹦跳跳"<<endl;
    }
    void fly()override{
        cout<<"乌鸦飞翔"<<endl;
    }
};

class Ostrich
:public Bird{
public:
    void eat()override{
       cout<<"鸵鸟吃东西"<<endl; 
    }
    void walk()override{
        cout<<"鸵鸟散步"<<endl;
    }
    void chirp()override{
        cout<<"鸵鸟蹦蹦跳跳"<<endl;
    }
};
void test0(){
    unique_ptr<Crow> crow1(new Crow());
    crow1->eat();
    crow1->walk();
    crow1->chirp();
    crow1->fly();

    unique_ptr<Ostrich> ost1(new Ostrich());
    ost1->eat();
    ost1->walk();
    ost1->chirp();

}
int main(){
    test0();
    return 0;
}
