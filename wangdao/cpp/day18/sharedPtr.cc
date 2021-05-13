#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::vector;
using std::vector;

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
    shared_ptr<int> sp(new int(10));
    cout << "*sp = " << *sp << endl;
    cout << "sp.get() = " << sp.get() << endl;
    cout<<"sp.use_count()="<<sp.use_count()<<endl;

    cout << endl << endl;
    shared_ptr<int> sp2(sp);//共享所有权,使用浅拷贝
    cout << "*sp = " << *sp << endl;
    cout << "sp.get() = " << sp.get() << endl;
    cout << "sp.use_count() = " << sp.use_count() << endl;
    cout << "*sp2 = " << *sp2 << endl;
    cout << "sp2.get() = " << sp2.get() << endl;
    cout << "sp2.use_count() = " << sp2.use_count() << endl;
    cout << endl << endl;


    shared_ptr<int> sp3(new int(10));
    sp3 = sp;//赋值
    cout << "*sp = " << *sp << endl;
    cout << "sp.get() = " << sp.get() << endl;
    cout << "sp.use_count() = " << sp.use_count() << endl;
    cout << "*sp3 = " << *sp3 << endl;
    cout << "sp3.get() = " << sp3.get() << endl;
    cout << "sp3.use_count() = " << sp3.use_count() << endl;

    
    cout << endl << endl;
    shared_ptr<int> sp4(std::move(sp));//通过移动语义转移sp的所有权
    cout << "*sp3 = " << *sp3 << endl;
    cout << "sp3.get() = " << sp3.get() << endl;
    cout << "sp3.use_count() = " << sp3.use_count() << endl;
    cout << "*sp4 = " << *sp4 << endl;
    cout << "sp4.get() = " << sp4.get() << endl;
    cout << "sp4.use_count() = " << sp4.use_count() << endl;
}
int main(int argc, char **argv)
{
    test();
    return 0;
}


