#include <iostream>

using std::cout;
using std::endl;

//模板的参数有两种类型
//1、类型参数
//2、非类型参数 常量表达式 整型:char/short/int/long
template <typename T = int, short kMin = 10> 
T multiply(T x, T y)
{
    return x * y * kMin;
}

int main(int argc, char **argv)
{
    int ia = 3, ib = 4;
    int da = 3.3, db = 4.4;
    cout << "multiply(ia, ib) = " << multiply(ia, ib) << endl;
    cout << "multiply(ia, ib) = " << multiply<int, 4>(ia, ib) << endl;
    cout << "multiply(ia, ib) = " << multiply<double, 4>(da, db) << endl;
    return 0;
}


