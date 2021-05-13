#include <iostream>

using std::cout;
using std::endl;

class Test{
public:   
    Test(){
        cout<<"Test()"<<endl;
    }
    ~Test(){
        cout<<"~Test()"<<endl;
    }
};
class Base{
public:
#if 0
    Base(){
        cout<<"Base()"<<endl;
    }
#endif
    Base()=default;
    Base(double base):_base(base){
        cout<<"Base(double)"<<endl;
    }
    ~Base(){
        cout<<"~Base()"<<endl;
    }
private:
    double _base;
};
class Derived:public Base{
public:
#if 1
    Derived(double derived):Base(derived),_derived(derived){
        cout<<"Derived(double)"<<endl;
    }
    ~Derived(){
        cout<<"~Derived()"<<endl;
    }
#endif 
private:
    double _derived;
    Test test;
};
int main()
{
    Derived da(1);//在创建派生类对象的时候，会调用派生类构造函数，在调用派生类构造函数的过程中，会调用基类构造函数，完成基类部分的初始化
    return 0;
}

