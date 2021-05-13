#include<stdlib.h>
#include<pthread.h>
#include<iostream>

using std::cout;
using std::endl;

class Singleton
{ 
public:
    static Singleton *getInstance()
    {
        pthread_once(&_once, init);
        return _pInstance;
    }

    static void init()
    {
        _pInstance = new Singleton();
        atexit(destroy);
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
    static pthread_once_t _once;
};
Singleton *Singleton::_pInstance = nullptr; //饱汉模式(懒汉模式)
/* Singleton *Singleton::_pInstance = getInstance();//饿汉模式 */
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(){
    Singleton::getInstance();
    return 0;
}
