#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;

class Child;

class Parent
{
public:
    Parent()
    {
        cout << "Parent()" << endl;
    }
    ~Parent()
    {
        cout << "~Parent()" << endl;
    }

    shared_ptr<Child> pParent;
};

class Child
{
public:
    Child()
    {
        cout << "Child()" << endl;
    }

    ~Child()
    {
        cout << "~Child()" << endl;
    }

    shared_ptr<Parent> pChild;
};


void test()
{
    //循环引用可能导致内存泄漏
    shared_ptr<Parent> parentPtr(new Parent());
    shared_ptr<Child> childPtr(new Child());
    cout << "parentPtr.use_count() = " << parentPtr.use_count() << endl;
    cout << "childPtr.use_count() = " << childPtr.use_count() << endl;
    
    cout << endl << endl;
    parentPtr->pParent = childPtr;//sp = sp
    childPtr->pChild = parentPtr;
    cout << "parentPtr.use_count() = " << parentPtr.use_count() << endl;
    cout << "childPtr.use_count() = " << childPtr.use_count() << endl;
}
int main(int argc, char **argv)
{
    test();
    return 0;
}


