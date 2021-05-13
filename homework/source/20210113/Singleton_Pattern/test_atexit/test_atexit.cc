#include<iostream>
using std::cout;
using std::endl;

class Singleton
{ 
public:
    static Singleton *getInstance()
    {
        //对于多线程环境，不安全
        if(nullptr == _pInstance)
        {
            _pInstance = new Singleton();
            atexit(destroy);
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
    } ~
    Singleton()
    {
        cout << "~Singleton()" << endl;
    }
private:
    static Singleton *_pInstance;
};
/* Singleton *Singleton::_pInstance = nullptr; //饱汉模式(懒汉模式)*/
Singleton *Singleton::_pInstance = getInstance();//饿汉模式

int main(){
    Singleton::getInstance();
    return 0;
}
