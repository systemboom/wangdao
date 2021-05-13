#include <iostream>

using std::cout;
using std::endl;

#include <string>
using std::string;

template <typename T>//模板参数列表
T add(T x, T y)
{
    cout << "T add(T, T)" << endl;
    return x + y;
}

void test()
{
    int ia = 3, ib = 4, ic = 5;
    double da = 1.1, db = 5.5;
    char ca = 'a', cb = 1;

    string s1 = "hello";
    string s2 = "world";

    cout << "add(ia, ib) = " << add(ia, ib) << endl;//隐式实例化
    cout << "add(da, db) = " << add<double>(da, db) << endl;//显示实例化
    cout << "add(ca, cb) = " << add(ca, cb) << endl;
    cout << "add(s1, s1) = " << add(s1, s2) << endl;
}

int main(int argc, char **argv)
{
    test();
    return 0;
}
