#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class RAII
{
public:
    //通过构造函数托管资源
    RAII(T *data)
    : _data(data)
    {
        cout << "RAII(T *)" << endl;
    }
    //访问资源的方法
    T *operator->()
    {
        return _data;
    }

    T &operator*()
    {
        return  *_data;
    }

    T *get() const
    {
        return _data;
    }

    void reset(T *data)
    {
        if(_data)
        {
            delete _data;
            _data = nullptr;
        }
        _data = data;
    }
    RAII(const RAII &rhs) = delete;
    RAII &operator=(const RAII &rhs) = delete;

    //通过析构函数释放资源
    ~RAII()
    {
        cout << "~RAII()" << endl;
        if(_data)
        {
            delete _data;
            _data = nullptr;
        }
    }
private:
    T *_data;
};

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
        cout << "(" << _ix
             << ", " << _iy
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

int main(int argc, char **argv)
{
    /* Point *pt = new Point(1, 2); */
    /* delete pt; */
    //vector<Point>
    //ppt本身是一个RAII的栈对象
    //ppt他的使用类似于一个指针
    RAII<Point> ppt(new Point(1, 2));
    ppt->print();
    //ppt.operator->().print();

    cout << endl;
    /* RAII<Point> ppt2 = ppt; */

    return 0;
}


