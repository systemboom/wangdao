#include <iostream>

using std::cout;
using std::endl;

class Base{
public:
    Base(){
        cout<<"Base()"<<endl;
    }
private:
    double _base;
};
class Derived:public Base{
public:
    Derived(double derived):_derived(derived){
        cout<<"Derived(double)"<<endl;
    }
private:
    double _derived;
};
int main()
{
    Derived da(10);//在创建派生类对象的时候，会调用派生类构造函数，在调用派生类构造函数的过程中，会调用基类构造函数，完成基类部分的初始化
    return 0;
}

