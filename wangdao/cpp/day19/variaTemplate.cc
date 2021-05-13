#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//可变模板参数可以传0到任意个参数、类型可以不一样
template <typename... Args>//Args称为模板参数包
void print(Args... args)//args是函数参数包
{
    cout << "sizeof...(Agrs) = " << sizeof...(Args) << endl;
    cout << "sizeof...(agrs) = " << sizeof...(args) << endl;

    /* cout << (args...) << endl; */
    /* cout << (...args) << endl; */
    /* cout << ( args) << endl; */
}

void display()
{
    cout << endl;
}
template <typename T, typename... Args>
void display(T t, Args... args)
{
    cout << t << " ";
    display(args...);//当... 位于args右边的时候叫做解包
    //display(args1) display(args2) .... display(argsN)
}

void test()
{
    string s1 = "hello";

    print();
    print(1, 2.2);
    print('a', true, s1);
    print(1, 2.2, 'b', "hello");
}
void test2()
{
    string s1 = "hello";

    display();
    //cout << endl;
    
    display(1, 2.2);
    //cout << 1 << " ";
    //display(2.2);
    //  cout << 2.2 << " ";
    //  display(); 
    //    cout << endl;

    display('a', true, s1);
    //cout << 'a' << " ";
    //display(true, s1);
    //   cout << 1 << " ";
    //   display(s1);
    //      cout << s1 << " ";
    //      display();
    //        cout << endl;
    display(1, 2.2, 'b', "hello");
    //cout << 1 << " ";
    //display(2.2, 'b', "hello");
    //   cout << 2.2 << " ";
    //   display('b', "hello");
    //      cout << 'b' << " ";
    //      display("hello");
    //         cout << "hello" << " ";
    //         display();
    //            cout << endl;
}



template <class T>
T sum(T t)
{
    return t;
}

template <typename T, typename... Args>
T sum(T t, Args... args)
{
    return t + sum(args...);
}

void test3()
{
    cout << "sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) = " 
         << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
}


int main(int argc, char **argv)
{
    test3();
    return 0;
}
