#ifndef _NOCOPYABLE_H_
#define _NOCOPYABLE_H_
class Noncopyable{
    protected:
        Noncopyable(){}
        ~Noncopyable(){}
        Noncopyable(const Noncopyable&)=delete;
        Noncopyable & operator=(const Noncopyable &) = delete;
};
#endif
