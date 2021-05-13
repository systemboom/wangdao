#include<iostream>
using std::cout;
using std::endl;

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
class Point3D:private Point{
public:
    Point3D(int ix=0,int iy=0,int iz=0):Point(ix,iy){
        cout<<"Point3D(int ix=0,int iy=0,int iz=0)"<<endl;
    }
    void print() const{
        cout<<"("<<_ix    //private 
           // <<","<<_iy   //基类的私有成员不能在类外进行访问
            <<","<<getY()//private 
            <<","<<_iz
            <<")"<<endl; 
    }
    ~Point3D(){
        cout<<"~Point3D()"<<endl;
    }
private:
    int _iz;
};
class Point$D:private Point3D{
public:
    void show()const{
        cout<<"("<<_ix  //private,error 
            //<<","<<_iy   //基类的私有成员不能在类外进行访问
            <<","<<getY()//private,基类中的public成员经过protected继承之后变为protected：
           /* <<","<<_iz */
            <<","<<_im
            <<")"<<endl; 
    }
private:
    int _im;
}
int main(){
    cout<<"hello world"<<endl;
    /* pt3d._ix=10; */
    /* cout<<pt3d.getY()<<endl; */ 
    return 0;
}
