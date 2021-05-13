 ///
 /// @file    function.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2020-06-27 11:52:45
 ///
 
#include <iostream>
#include <functional>

using namespace std;

void display()
{
	cout << "display()" << endl;
}

struct Task
{
	void display() 
	{
		cout << "Task::display()" << endl;
	}
};
 
void test0()
{
	function<void()> f = display;
	f();

	f = bind(&Task::display, Task());
	f();
	
}
 
int main(void)
{
	test0();
	return 0;
}

