#include"Line.h"
class Line::LineImpl
{ 
public:
    LineImpl(int x1, int y1, int x2, int y2);
    void printLineImpl() const;

private:
    class Point
    { 
    public:
        Point(int x = 0, int y = 0): _x(x), _y(y){
            cout<<"Point()"<<endl;
        }
        void print() const{
            cout<<"("<<_x<<","<<_y<<")";
        }
        ~Point(){
            cout<<"~Point()"<<endl;
        }
    private:
        int _x;
        int _y;
    };

    Point _pt1;
    Point _pt2;
};

Line::LineImpl::LineImpl(int x1, int y1, int x2, int y2): _pt1(x1, y1), _pt2(x2, y2){
            cout<<"LineImpl()"<<endl;
}

void Line::LineImpl::printLineImpl() const
{
    _pt1.print();
    cout << " ---> ";
    _pt2.print();
    cout << endl;
}

Line::Line(int x1, int y1, int x2, int y2): _pimpl(new LineImpl(x1, y1, x2, y2)){
            cout<<"Line()"<<endl;
}

Line::~Line() { 
    cout<<"~Line()"<<endl;
    if(_pimpl){
        delete _pimpl; 
        _pimpl=nullptr;
    }
}

void Line::printLine() const{
    _pimpl->printLineImpl();
}
