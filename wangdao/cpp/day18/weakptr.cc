#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::weak_ptr;
using std::shared_ptr;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Point(int = 0, int = 0)" << endl;
    }

    void print() const
    {
        cout << "(" <<_ix
              << ","  << _iy
              << ")" << endl;
    }
    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};

void test()
{
    /* weak_ptr<Point> wp(new Point(1, 2));//error */
    weak_ptr<Point> wp;

    {
        shared_ptr<Point> sp(new Point(1, 2));
        wp = sp;
        cout << "wp.use_count = " << wp.use_count() << endl;
        cout << "sp.use_count = " << sp.use_count() << endl;

        //weak_ptr不能直接获取资源
        cout << "wp.expired = " << wp.expired() << endl;
        shared_ptr<Point> sp2 = wp.lock();
        if(sp2)
        {
            cout << "提升成功" << endl;
            cout << "*sp2 = ";
            sp2->print();
        }
        else
        {
            cout << "提升失败" << endl;
        }
    }

    cout << endl << "当块语句执行结束之后 : "  << endl;
    cout << "wp.expired = " << wp.expired() << endl;
    //weak_ptr不能直接获取资源
    shared_ptr<Point> sp2 = wp.lock();
    if(sp2)
    {
        cout << "提升成功" << endl;
        cout << "*sp2 = ";
        sp2->print();
    }
    else
    {
        cout << "提升失败" << endl;
    }
}
int main(int argc, char **argv)
{
    test();
    return 0;
}

