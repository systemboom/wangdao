#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;


class Point
: public std::enable_shared_from_this<Point>
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

    /* Point *addPoint(Point *pt) */
    shared_ptr<Point> addPoint(Point *pt)
    {
        _ix += pt->_ix;
        _iy += pt->_iy;

        //this指针是一个裸指针
        /* return shared_ptr<Point>(this); */
        return shared_from_this();
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
    //error，将同一个裸指针用不同的智能指针进行托管
    Point *pt = new Point(10, 20);
    unique_ptr<Point> up1(pt);
    unique_ptr<Point> up2(pt);
}

void test2()
{
    //error，将同一个裸指针用不同的智能指针进行托管
    unique_ptr<Point> up1(new Point(1, 2));
    unique_ptr<Point> up2(new Point(30, 50));
    up1.reset(up2.get());
    
}

void test3()
{
    shared_ptr<Point> sp1(new Point(1, 2));
    cout << "sp1 = ";
    sp1->print();

    cout << endl;
    shared_ptr<Point> sp2(new Point(3, 4));
    cout << "sp2 = ";
    sp2->print();

    cout << endl;
    shared_ptr<Point> sp3(sp1->addPoint(sp2.get()));
    cout << "sp3 = ";
    sp3->print();
}
int main(int argc, char **argv)
{
    test3();
    return 0;
}


