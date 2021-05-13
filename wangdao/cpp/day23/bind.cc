#include<iostream>
#include<functional>

using std::cout;
using std::endl;
using std::bind;

int add(int x,int y){
    return x+y;
}
class Test{
public:
    int add(int x,int y){
        return x+y;
    } 
};
void test(){
    auto f=bind(add,2,3);
    cout<<"f()="<<f()<<endl;;
    
    Test test;
    auto f2=bind(&Test::add,&test,10,20);
    cout<<"f2()="<<f2()<<endl;
}

typedef int(*pFunc)();

int func1(){
    return 5;
}

int func2(){
    return 15;
}
void func3(int x1,int x2,int x3,const int x4,int x5){
    cout<<"("<<x1
        <<","<<x2
        <<","<<x3
        <<","<<x4
        <<")"<<endl;
}
void test3(){
    using namespace std::placeholders;
    int number=100;
    bind(func,2,1,2,number,number);

}
void test2(){
    pFunc f=func1;//对于f注册回调函数，C语言是可以实现多态的(通过函数指针实现的)
    cout<<"f()="<<f()<<endl;//执行回调函数
    
    f=func2;//对于f注册回调函数，C语言是可以实现多态的(通过函数指针实现的)
    cout<<"f2()="<<f()<<endl;
    
    //占位符
    //bind可以改变函数的形态，本来f传两个参数，经过bind可以只传一个参数或者不传参数
    auto f3=bind(add,1,std::placeholders::_1);  
    cout<<"add(10)="<<f3(10)<<endl;
    
}

int main(){
    test2();
    test();
    return 0;
}
