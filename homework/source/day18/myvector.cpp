#include<iostream>
#include<memory>
using std::cout;
using std::endl;
using std::allocator;
using std::uninitialized_copy;

template<typename T>
class Vector
{
public:
	Vector():_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}
    ~Vector() {
		if (_start) {
			while (_start != _finish) {
				_alloc.destroy(--_finish);
			}
			_alloc.deallocate(_start,capacity());
		}
	}

	void push_back(const T &val) {
        if(size()==capacity()){
            reallocate();
        }
        _alloc.construct(_start++,val);
	}

	void pop_back() {
		if (size() > 0) _alloc.destroy(--_finish);
	}

	size_t size() {
		return _finish - _start;
	}
	inline size_t capacity() {
		return _end_of_storage - _start;
	}
    
    T & operator[](size_t idx){
        return _start[idx];
    }

    T *begin(){
        return _start;
    }
    
    T *end(){
        return _finish;
    }

private:
	void reallocate() {//重新分配内存,动态扩容要用的
		size_t tmp = capacity();
		size_t new_tmp=(tmp == 0 ? 1:tmp << 1);//新空间大小
        T *new_start = _alloc.allocate(new_tmp);
		if (_start) {
			uninitialized_copy(_start, _finish, new_start);
			while (_start != _finish) {
				_alloc.destroy(--_finish);
			}
			_alloc.deallocate(_start, capacity());
		}
		_start = new_start;
		_finish = _start + tmp;
        _end_of_storage=_start+new_tmp;

	}
private:
	static allocator<T> _alloc;

	T * _start;      //指向数组中的第一个元素
	T * _finish; //指向最后一个实际元素之后的那个元素
	T * _end_of_storage;        //指向数组本身之后的位置
};
template<typename T>
allocator<T> Vector<T>:: _alloc;
int main(){
    Vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    v1.pop_back();
    for(auto p=v1.begin();p!=v1.end();p++){
            cout<<*p<<endl;
    }
    return 0;
}























