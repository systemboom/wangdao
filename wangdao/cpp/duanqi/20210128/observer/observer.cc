#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <algorithm>
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::unique_ptr;

class Subject;
class Observer{
public:
	virtual void update() = 0;

//	virtual void update(const string & msg) = 0;


//	virtual void update(Subject * psub) = 0;
	virtual ~Observer(){}
};

class Baby
: public Observer{
public:
	Baby(const string & name)
	: _name(name){}

	void update() override{
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
: public Observer{
public:
	Nurse(const string & name)
	: _name(name){}

	void update() override{

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

class Subject{
public:
	virtual void attach(Observer * ob) = 0;
	virtual void detach(Observer * ob) = 0;
	virtual void notify() = 0;
	virtual ~Subject(){}
};
class Ring
: public Subject{
public:
	Ring()
	: _isAlarming(false){}

	virtual void attach(Observer * ob) override{
		auto iter = std::find(_oblist.begin(), _oblist.end(), ob);
		if(iter == _oblist.end()) {
			_oblist.push_back(ob);
		}
	}

	virtual void detach(Observer * ob) override	{
		auto iter = std::find(_oblist.begin(), _oblist.end(), ob);
		if(iter != _oblist.end()) {
			_oblist.erase(iter);
		}
	}

	virtual void notify() {
		cout << " the ring is alarming!" << endl;
		for(auto & ob : _oblist) {
			ob->update();
		}
	}

	void bePressedDown(){
		
		_isAlarming = true;
		if(_isAlarming) {
			notify();    
			
			_isAlarming = false;
		}
	}

	~Ring() {	
        cout << "~Ring()" << endl;	
    }
private:
	
	list<Observer *> _oblist;
	bool _isAlarming;
};
class Guest{
public:
	Guest(const string & name)
	: _name(name){
	}

	void knockAtDoor(Ring & ring){
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

