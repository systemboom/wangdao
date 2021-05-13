#include <math.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

class Figure{
public:
    virtual void display() const =0;
	virtual double area()=0;
    virtual ~Figure() {
        cout<<"~Figure"<<endl;
    }
};

class Circle
: public Figure{
public:
	Circle(double radius)
	: _radius(radius){}

	void display() const{	
        cout << "circle";	
    }

	double area(){
		return 3.14159 * _radius * _radius;
	}

	~Circle() {	
        cout << "~Circle()" << endl;	
    }

private:
	double _radius;
};

class Rectangle
: public Figure{
public:
	Rectangle(double length, double width)
	: _length(length)
	, _width(width){}

	~Rectangle() { 
        cout << "~Rectangle()" << endl; 
    }

	void display() const{	
        cout << "rectangle";	
    }

	double area(){
        return _length * _width;
    }

private:
	double _length;
	double _width;
};

class Triangle
: public Figure{
public:
	Triangle(double a, double b, double c)
	: _a(a)
	, _b(b)
	, _c(c)
	{}

	~Triangle() {
        cout << "~Triangle()" << endl;
    }

	void display() const{
        cout << "triangle";
    }

	double area(){
		double p = (_a + _b + _c) / 2;
		return sqrt(p * (p - _a) * (p - _b) * (p - _c));
	}

private:
	double _a;
	double _b;
	double _c;
};

void display(Figure * fig){
	fig->display();
	cout << "的面积是:" << fig->area() << endl;
}
class Factory {
public:
	static Figure * create(int type){

		Figure * fig = nullptr;
		switch(type){
		case 0:

			fig = new Rectangle(10, 4);
			break;
		case 1:

			fig = new Circle(10);
			break;
		case 2:

			fig = new Triangle(3, 4, 5);
			break;


		default:
			break;
		}
		return fig;
	}
    static Rectangle createRectangle(){
		Rectangle rectangle(10, 4);
		return rectangle;
	}
    static Circle createCircle(){
		Circle circle(10);
		return circle;
	}
    static Triangle createTriangle(){
		Triangle triangle(3, 4, 5);
		return triangle;
	}
};
#if 0
void test1(){
    Rectangle rectangle(4, 5);
    Circle circle(10);
    Triangle triangle(3, 4, 5);

	display(&rectangle);
	display(&circle);
	display(&triangle);
}
#endif
int main(){
    Rectangle rectangle = Factory::createRectangle();
	Circle circle = Factory::createCircle();
	Triangle triangle = Factory::createTriangle();

	display(&rectangle);
	display(&circle);
	display(&triangle);
    return 0;
}
