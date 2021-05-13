 ///
 /// @file    observer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-28 14:38:03
 ///

//1. 自定义头文件
//#include "*.hpp "   

//2. C标准头文件
#include <stdlib.h>
#include <time.h>

//3. C++标准头文件
#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <algorithm>

//4. 第三方库 log4cpp, tinyxml2
//#include <> 

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::unique_ptr;

//using namespace std;

class Subject;// 类的前向声明

class Observer
{
public:
	virtual void update() = 0;
	//1. 推送的是消息本身, 
	//推模式, 观察者被动接收信息
	virtual void update(const string & msg) = 0;

	//2. 推送的是主题的指针, 该指针可以获取目标的状态
	//拉模式, 观察者可以主动选择是否获取目标的信息
	virtual void update(Subject * psub) = 0;
	virtual ~Observer(){}
};

class Baby
: public Observer
{
public:
	Baby(const string & name)
	: _name(name)
	{}

	void update() override
	{
		::srand(::clock());
		int number = ::rand() % 100;
		cout << "number = " << number << endl;
		if(number > 80) {
			cout << "Baby " << _name
				 << " starts crying loundly!" << endl;
		} else {
			cout << "Bayb " << _name 
				 << "is sleeping sweetly!" << endl;
		}
	}

private:
	string _name;
};

class Nurse
: public Observer
{
public:
	Nurse(const string & name)
	: _name(name)
	{}

	void update() override
	{
		//::srand(::time(NULL));
		::srand(::clock());
		int number = ::rand() % 100;
		cout << "number = " << number << endl;
		if(number < 80) {
			cout << "Nurse " << _name
				 << " is ready to open the door!" << endl;
		} else {
			cout << "Nurse " << _name 
				 << "is sleeping sweetly!" << endl;
		}
	}
private:
	string _name;
};


class Subject
{
public:
	virtual void attach(Observer * ob) = 0;
	virtual void detach(Observer * ob) = 0;
	virtual void notify() = 0;
	virtual ~Subject(){}
};


class Ring
: public Subject
{
public:
	Ring()
	: _isAlarming(false)
	{}

	virtual void attach(Observer * ob) override
	{
		//1. 判断参数ob是否已经在List中
		auto iter = std::find(_oblist.begin(), _oblist.end(), ob);
		if(iter == _oblist.end()) {
			_oblist.push_back(ob);
		}
	}

	virtual void detach(Observer * ob) override
	{
		auto iter = std::find(_oblist.begin(), _oblist.end(), ob);
		if(iter != _oblist.end()) {
			_oblist.erase(iter);
		}
	}

	virtual void notify() 
	{
		cout << " the ring is alarming!" << endl;
		for(auto & ob : _oblist) {
			ob->update();
		}
	}

	void bePressedDown()
	{
		//表示门铃被按响了, 需要改变状态
		_isAlarming = true;
		if(_isAlarming) {
			notify();    
			//做完通知之后，再将门铃的状态设置为false
			_isAlarming = false;
		}
	}

	~Ring() {	cout << "~Ring()" << endl;	}
private:
	//用户分类之后，就可以推送不同类别的消息
	list<Observer *> _oblist;//普通用户     
	list<Observer *> _goldeList;//黄金用户
	list<Observer *> _silverList;//白银用户
	list<Observer *> _DiamondList;//钻石用户

	bool _isAlarming;
};

class Guest
{
public:
	Guest(const string & name)
	: _name(name)
	{
	
	}

	void knockAtDoor(Ring & ring)
	{
		cout << "Guest " << _name << " is knocking at the door!" << endl;
		ring.bePressedDown();
	}


private:
	string _name;
};


 
void test0() 
{
	Guest guest("哩哩老师");
	Ring ring;

	unique_ptr<Observer> baby1(new Baby("风华"));
	unique_ptr<Observer> baby2(new Baby("丸子"));
	unique_ptr<Observer> nurse1(new Nurse("咸鱼学长"));
	unique_ptr<Observer> nurse2(new Nurse("楼楼姐"));

	//当门铃的状态发生改变时，会影响其他观察者的行为
	ring.attach(baby1.get());
	ring.attach(baby2.get());
	ring.attach(nurse1.get());
	ring.attach(nurse2.get());
 
	guest.knockAtDoor(ring);

	ring.detach(nurse1.get());
	cout << endl;

	guest.knockAtDoor(ring);
} 
 
int main(void)
{
	test0();
	return 0;
}

