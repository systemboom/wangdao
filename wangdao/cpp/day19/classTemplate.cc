#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//类模板
template <typename T, size_t kSize = 10>
class Stack
{
public:
    Stack()
    : _top(-1) 
    , _data(new T[kSize]())
    {

    }
    ~Stack();
    bool empty() const;
    bool full() const;
    void push(const T &t);
    void pop();
    T top() const;
private:
    int _top;
    T *_data;
};


template<typename T,size_t ksize>
Stack<T,ksize>::~Stack()
{
    if(_data)
    {
        delete[] _data;
        _data=nullptr;
    }
}

template <typename T, size_t kSize>
bool Stack<T, kSize>::empty() const
{
    return -1 == _top;//_top = -1
}
template <typename T, size_t kSize>
bool Stack<T, kSize>::full() const
{
    return _top == kSize - 1;
}

template <typename T, size_t kSize>
void Stack<T, kSize>::push(const T &t)
{
    if(!full())
    {
        _data[++_top] = t;
    }
    else
    {
        cout << "The Stack is full, cannot push any data" << endl;
    }

}
template <typename T, size_t kSize>
void Stack<T, kSize>::pop()
{
    if(!empty())
    {
        --_top;
    }
    else
    {
        cout << "The Stack is empty" << endl;
    }

}
template <typename T, size_t kSize>
T Stack<T, kSize>::top() const
{
    return _data[_top];
}

void test()
{
    Stack<int, 8> st;
    cout << "栈是不是空的?" << st.empty() << endl;
    st.push(1);
    cout << "栈是不是空的?" << st.empty() << endl;

    for(size_t idx = 1; idx != 15; ++idx)
    {
        st.push(idx);
    }
    cout << "栈是不是满的?" << st.full() << endl;
    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout << "栈是不是空的?" << st.empty() << endl;

}
void test1()
{
    /* Stack<string, 12> st; */
    Stack<string> st;
    cout << "栈是不是空的?" << st.empty() << endl;
    st.push(string("aa"));
    cout << "栈是不是空的?" << st.empty() << endl;
#if 1
    for(size_t idx = 1; idx != 15; ++idx)
    {
        st.push(string(2, 'a' + idx));
    }
    cout << "栈是不是满的?" << st.full() << endl;
    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout << "栈是不是空的?" << st.empty() << endl;
#endif
}
int main(int argc, char **argv)
{
    test1();
    return 0;
}

