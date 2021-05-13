#include<iostream>
using std::cout;
using std::endl;
//1.不论什么继承方式，派生类中都不能访问基类私有成员
//2.不论什么继承方式，派生类中除了基类私有成员不能访问，其他都可以访问
//3.不论什么继承方式，派生类只能访问public继承的public成员，派生类对象都不能访问
//4.若不写继承方式，默认继承方式是私有的
class Point{
public:
    Point(int ix=0,int iy=0):_ix(ix),_iy(iy){
        cout<<"Point()"<<endl;
    }
    ~Point(){
        cout<<"~Point()"<<endl;
    }
    int getY() const{
        return _iy;
    }

protected:
    int _ix;
private:
    int _iy;
};


class Point3D:public Point{
public:
    Point3D(int ix=0,int iy=0,int iz=0):Point(ix,iy){
        cout<<"Point3D(int ix=0,int iy=0,int iz=0)"<<endl;
    }
    
    void print() const{
        cout<<"("<<_ix//protected 
            // <<","<<_iy   //基类的私有成员不能在类外进行访问
            <<","<<getY()//public   
            <<","<<_iz//private
            <<")"<<endl; 
    }

    ~Point3D(){
        cout<<"~Point3D()"<<endl;
    }
private:
    int _iz;
};
int main(){
    cout<<"hello world"<<endl;
    Point3D pt3d(1,2,3);
   // pt3d._ix=10;
    cout<<pt3d.getY()<<endl;
    return 0;
}
