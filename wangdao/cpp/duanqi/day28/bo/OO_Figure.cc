 ///
 /// @file    Figure.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-06-28 14:31:43
 ///
 
#include <math.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;

//配置文件的形式:
//	*.txt 
//	xml
//	json
class Figure
{
public:
	virtual void display() const =0;
	virtual double area()=0;

	virtual ~Figure() {}
};

class Circle
: public Figure
{
public:
	Circle(double radius)
	: _radius(radius)
	{}

	void display() const
	{	cout << "circle";	}

	double area()
	{
		return 3.14159 * _radius * _radius;
	}

	~Circle() {	cout << "~Circle()" << endl;	}

private:
	double _radius;
};

class Rectangle
: public Figure
{
public:
	Rectangle(double length, double width)
	: _length(length)
	, _width(width)
	{}

	~Rectangle() { cout << "~Rectangle()" << endl; }

	void display() const
	{	cout << "rectangle";	}

	double area()
	{	return _length * _width;	}

private:
	double _length;
	double _width;
};

class Triangle
: public Figure
{
public:
	Triangle(double a, double b, double c)
	: _a(a)
	, _b(b)
	, _c(c)
	{}

	~Triangle() {	cout << "~Triangle()" << endl;	}

	void display() const
	{	cout << "triangle";}

	double area()
	{
		double p = (_a + _b + _c) / 2;
		return sqrt(p * (p - _a) * (p - _b) * (p - _c));
	}

private:
	double _a;
	double _b;
	double _c;
};

void display(Figure * fig)
{
	fig->display();
	cout << "的面积是:" << fig->area() << endl;
}


//静态工厂方法
//问题:
//	  1. 违反单一职责原则
//	  2. 违反开闭原则
class Factory {
public:
	static Figure * create(int type)
	{
		//....预处理
		Figure * fig = nullptr;
		switch(type){
		case 0:
			///获取长和宽
			fig = new Rectangle(10, 4);
			break;
		case 1:
			//int radius = config->getCircleRadius();
			fig = new Circle(10);
			break;
		case 2:
			//获取3边的值
			fig = new Triangle(3, 4, 5);
			break;
//		case 3:
			//获取菱形的数据
//			fig = new Diamond();

		default:
			break;
		}
		return fig;
	}

	static Rectangle createRectangle()
	{
		//获取数据的时候，是通过配置文件进行的
		//.....预处理
		//读取配置文件的信息
		//
		//Configuration  ==> 单例模式
		Rectangle rectangle(10, 4);
		return rectangle;
	}

	static Circle createCircle()
	{
		//.....预处理
		Circle circle(10);
		return circle;
	}

	static Triangle createTriangle()
	{
		//..... 预处理
		Triangle triangle(3, 4, 5);
		return triangle;
	}
};

void test1()
{
	//length, width: 4, 5
	//radius: 10
	//a: 3, b:4, c:5
	
	
	//预处理: 读取配置文件 xml
	//
	Rectangle rectangle(4, 5);

	//
	//预处理: 读取配置文件 xml
	//
	Circle circle(10);

	//
	//预处理: 读取配置文件 xml
	//
	Triangle triangle(3, 4, 5);

	display(&rectangle);
	display(&circle);
	display(&triangle);

}

#if 0
int main(void)
{
	test1();
	return 0;
}

#endif


int main(void)
{
	Rectangle rectangle = Factory::createRectangle();
	Circle circle = Factory::createCircle();
	Triangle triangle = Factory::createTriangle();

	display(&rectangle);
	display(&circle);
	display(&triangle);

	return 0;
}

