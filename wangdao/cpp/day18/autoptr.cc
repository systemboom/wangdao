#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::auto_ptr;


void test()
{
    //之前学的都叫做原生指针(裸指针),叫法与智能指针对应
    int *pt = new int(10);
    auto_ptr<int> ap(pt);
    cout << "*ap = " << *ap << endl;
    cout << "ap.get() = " << ap.get() << endl;
    cout << "pt = " << pt  << endl;

}

int main(int argc, char **argv)
{
    test();
    return 0;
}


