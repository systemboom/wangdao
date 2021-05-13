#include <iostream>
#include <memory>
using namespace std;

class Vehicle{
public:
    virtual void run()=0;
    virtual ~Vehicle(){}
};

class Tesla
:public Vehicle{
public:
    void run() {
        cout<<"Model3 启动"<<endl;
    }
};

class BYD
:public Vehicle{
public:
    void run(){
        cout<<"汉EV 启动"<<endl;
    }
};

class Geely
:public Vehicle{
public:
    void run(){
        cout<<"领克03 启动"<<endl;
    }
};
class Person
{
public:
    void getVehicle(Vehicle * vehicle)
    {
        _vehicle=vehicle;
    }
    void drive()
    {
        _vehicle->run();
    }
private:
    Vehicle * _vehicle;
};

void test1()
{
    Person p;
    unique_ptr<Vehicle> tesla(new Tesla());
    unique_ptr<Vehicle> han(new BYD());
    unique_ptr<Vehicle> geely(new Geely());
    
    p.getVehicle(tesla.get());
    p.drive();
    
    p.getVehicle(han.get());
    p.drive();
    
    p.getVehicle(geely.get());
    p.drive();
}
int main(){
    test1();
    return 0;
}

