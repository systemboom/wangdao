#include <iostream>

using std::cout;
using std::endl;

class A{
public:
    A(){
        cout<<"A()"<<endl;
    }
    void display() const{
        cout<<"void A::display()"<<endl;
    }
    ~A(){
        cout<<"~A()"<<endl;
    }
};

class B{
public:
    B(){
        cout<<"B()"<<endl;
    }
    void show() const{
        cout<<"void B::show()"<<endl;
    }
    ~B(){
        cout<<"~B()"<<endl;
    }
};

class C{
public:
    C(){
        cout<<"C()"<<endl;
    }
    void print() const{
        cout<<"void C::print()"<<endl;
    }
    ~C(){
        cout<<"~C()"<<endl;
    }
};
class D:public C,public B,public A{
public:
    D(){
        cout<<"D()"<<endl;
    }
    ~D(){
        cout<<"~D()"<<endl;
    }
};
int main()
{
    D d;
    d.display();
    d.show();
    d.print();
    std::cout << "Hello world" << std::endl;
    return 0;
}

