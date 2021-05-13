#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

class Building{
public:
    virtual void sale()=0;
    virtual string getQuality()=0;
    virtual ~Building(){}
};
class WankeBuiding
:public Building{
public:
    WankeBuiding()
    :_quality("高品质"){}

    void sale(){
        cout<<"万科"<<_quality<<"房子已出售"<<endl;
    }

    string getQuality(){
        return _quality;
    }
private:
    string _quality;
};
class LanguangBuiding
:public Building{
public:
    LanguangBuiding()
   :_quality("低品质"){}

    void sale(){
        cout<<"蓝光"<<_quality<<"房子已出售"<<endl;
    }
    string getQuality(){
        return _quality;
    }
private:
    string _quality;
};
 class Mediator{
public:
    Mediator()
    {
    
    shared_ptr<Building> wb1(new WankeBuiding());
    shared_ptr<Building> wb2(new WankeBuiding());
        _buildings.push_back(wb1);
        _buildings.push_back(wb2);
    }
    shared_ptr<Building> findBuilding(const string &demand)
    {
        for(auto &elem:_buildings)
            if(elem->getQuality()==demand)
                return elem;
        return nullptr;
    }
private:
    vector<shared_ptr<Building> > _buildings;
}; 
void test0(){
    Mediator m1;
    shared_ptr<Building> myBuilding=m1.findBuilding("高品质");
    myBuilding->sale();
}
int main(){
    test0();
    return 0;
}
