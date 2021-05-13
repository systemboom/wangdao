#include<iostream>

using std::cout;
using std::endl;

class Singleton
{ 
public:
    static Singleton * getInstance()
    {
        if(_pInstance == nullptr)
        {
            _pInstance = new Singleton();
        } 
        return _pInstance;
    }
private:
    class AutoRelease
    { 
    public:
        AutoRelease() {
            cout<<"AutoRelease()"<<endl;
        }
        ~AutoRelease(){
            cout<<"~AutoRelease()"<<endl;
            if(_pInstance)
            {
                delete _pInstance;
                _pInstance=nullptr;
            }
        }
    };

private:
    Singleton() {
        cout<<"Singleton()"<<endl;
    }
    ~Singleton() {
        cout<<"~Singleton()"<<endl;
    }

private:
    static Singleton * _pInstance;
    static AutoRelease _auto;
};
Singleton* Singleton::_pInstance=nullptr;
Singleton::AutoRelease Singleton::_auto;
int main(){
    Singleton::getInstance();
    return 0;
}
