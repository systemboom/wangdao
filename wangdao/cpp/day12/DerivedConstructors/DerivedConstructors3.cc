#include <iostream>

using std::cout;
using std::endl;

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
private:
    double _base;
};
class Derived:public Base{
public:
#if 1
    Derived(double derived):Base(derived),_derived(derived){
        cout<<"Derived(double)"<<endl;
    }
#endif 
private:
    double _derived;
};
int main()
{
    Derived da(1);//在创建派生类对象的时候，会调用派生类构造函数，在调用派生类构造函数的过程中，会调用基类构造函数，完成基类部分的初始化
    return 0;
}

