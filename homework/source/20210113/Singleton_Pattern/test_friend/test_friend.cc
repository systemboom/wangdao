#include<iostream>
using std::cout;
using std::endl;

class AutoRelease;

class Singleton
{
    friend AutoRelease;
public:
    static Singleton *getInstance(){
        if(nullptr == _pInstance){
            _pInstance = new Singleton();
        } 
        return _pInstance;
    } 
    static void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;//1、调用析构函数 2、operator delete
            _pInstance = nullptr;
        }
    }
private:
    Singleton()
    {
        cout << "Singleton()" << endl;
    } 
    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }
private:
    static Singleton *_pInstance;
};
Singleton *Singleton::_pInstance = nullptr;

class AutoRelease
{
public:
    AutoRelease()
    {
        cout << "AutoRelease()" << endl;
    } ~
    AutoRelease()
    {
        cout << "~AutoRelease()" << endl;
        if(Singleton::_pInstance)
        {
            delete Singleton::_pInstance;//1、调用析构函数 2、operator delete
            Singleton::_pInstance = nullptr;
        }
    }
};
int main(){
    Singleton::getInstance();
    AutoRelease ar;
    return 0;
}
