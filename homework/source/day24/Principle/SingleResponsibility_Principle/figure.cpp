#include<iostream>
using std::cout;
using std::endl;

class GeometryApp{
public:
    GeometryApp()
    {
        cout<<"GeometryApp()"<<endl;
    }
    ~GeometryApp()
    {
        cout<<"~GeometryApp()"<<endl;
    }
};

class Rectangle{
public:
    double area(double x,double y){
        GeometryApp app;
        return x*y;
    }
};

class GraphicalApp{
public:
    static void Graphical_App(){
        cout<<"static void GraphicalApp"<<endl;
    }
};

class RectangleUI
:public Rectangle{
public:
    void draw(){
        cout<<"RectangleUI"<<endl;
        GraphicalApp:: Graphical_App();
    }

};

class GUI{
public:
    void getresult(RectangleUI * rui){
        rui->draw();
    }
};
void test()
{
    Rectangle r;
    cout<<r.area(2,3)<<endl;
    
    RectangleUI *r1=new RectangleUI();
    r1->draw();
}

int main()
{
    test();
    return 0;
}

