#include"String.h"
#include<cstring>
String::String() :_pstr(nullptr) {};

String::String(const char *pstr):_pstr(new char[strlen(pstr)+1]) {
//构造函数
	strcpy(_pstr, pstr);
};

String::String(const String & rhs) :_pstr(new char[strlen(rhs._pstr) + 1]) {
//拷贝构造函数
	strcpy(this->_pstr, rhs._pstr);
}

String &String::operator=(const String & rhs) {
//赋值运算符函数
	this->_pstr = rhs._pstr;
	return *this;
}
String::~String() {
//析构函数
//	delete []_pstr;

 if(nullptr==_pstr){
        delete []_pstr;
        _pstr = nullptr;//防止野指针
    }
}

void String::print() {
	//cout << "_pstr=" << _pstr << endl;
	printf("_pstr=%s\n", _pstr);
}
