#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(double dx = 0, double dy = 0)
    : _dx(dx)
    , _dy(dy)
    {
        cout << "Point(double = 0, double = 0)" << endl;
    }

    //成员函数模板,成员函数模板也是可以设置默认值
    template <typename T = int>
    T func()
    {
        return (T)_dx;
    }
    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    double _dx;
    double _dy;
};

int main(int argc, char **argv)
{
    Point pt(1.1, 2.2);
    cout << "pt.func() = ";
    cout << pt.func<int>() << endl;
    cout << endl;
    cout << "pt.func() = ";
    cout << pt.func() << endl;
    return 0;
}
