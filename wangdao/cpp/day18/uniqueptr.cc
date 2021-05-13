#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::unique_ptr;
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
    unique_ptr<int> up(new int(10));
    cout << "*up = " << *up << endl;
    cout << "up.get() = " << up.get() << endl;

    cout << endl << endl;
    /* unique_ptr<int> up2(up);//error,独享资源的所有权 */

    cout << endl << endl;
    unique_ptr<int> up3(new int(10));
    /* up3 = up;//error,不能进行赋值操作 */

    
    cout << endl << endl;
    unique_ptr<int> up4(std::move(up));//通过移动语义转移up的所有权
    cout << "*up4 = " << *up4 << endl;
    cout << "up4.get() = " << up4.get() << endl;


#if 0
    cout << endl << endl;
    vector<Point *> numbers1;
    numbers1.push_back(new Point(1, 2));
#endif

    cout << endl << endl;

    unique_ptr<Point> up5(new Point(3, 4));//通过移动语义转移up的所有权
    vector<unique_ptr<Point>> numbers;
    numbers.push_back(unique_ptr<Point>(new Point(1, 2)));
    numbers.push_back(std::move(up5));
    /* numbers.push_back(up5); */
    numbers[0]->print();
    numbers[1]->print();



}
int main(int argc, char **argv)
{
    test();
    return 0;
}


