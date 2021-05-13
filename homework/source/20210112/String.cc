#include"String.h"

String::String():_pstr(nullptr){
    cout<<"String()"<<endl;
}

String::String(const char *pstr):_pstr(new char[strlen(pstr)+1]){
    cout<<"String(const char *pstr)"<<endl;
    strcpy(_pstr,pstr);
}	

//拷贝构造函数
String::String(const String &rhs):_pstr(new char[strlen(rhs._pstr)+1]){
    cout<<"String(const String &rhs)"<<endl;
    strcpy(_pstr,rhs._pstr);
}

String::~String(){
    cout<<"_String"<<endl;
    if(nullptr!=_pstr){
        delete[] _pstr;
        _pstr=nullptr;
    }
}

//赋值运算符重载
String & String::operator=(const String &rhs){
    cout<<"String &operator=(const String &)"<<endl;
    if(this!=&rhs){
        delete[] _pstr;
        _pstr=nullptr;
        _pstr=new char[strlen(rhs._pstr)+1]();
        strcpy(_pstr,rhs._pstr);
    }
    return *this;
}

//将const char *str转换为String
String & String::operator=(const char *str){
    cout<<"String &operator=(const char *)"<<endl;
   // *this=to_string(str);
    String temp(str);
    *this=temp;
    return *this;
}

//字符串拼接
String & String::operator+=(const String &rhs){
    cout<<"String &operator+=(const String &)"<<endl;
    
    String temp=*this;
    delete[] _pstr;
    _pstr=nullptr;
    _pstr=new char[strlen(temp._pstr)+strlen(rhs._pstr)+1];
    
    strcpy(_pstr,temp._pstr);
    strcat(_pstr,rhs._pstr);

    return *this;
}

String & String::operator+=(const char *){
    cout<<"String &operator+=(const String &)"<<endl;
    
    String temp(_pstr);
    *this+=temp;
    return *this;
}


char & String::operator[](std::size_t index){
    
    if(index >=0 && index < size()) {     
        return _pstr[index];
     } 
    else{
        static char nullchar = '\0';
        cerr << "下标越界！\n";
        return nullchar;
    }
}
const char & String::operator[](std::size_t index) const{
    
    if(index >=0 && index < size()) {     
        return _pstr[index];
     } 
    else{
        static char nullchar = '\0';
        cerr << "下标越界！\n";
        return nullchar;
    }
}

std::size_t String::size() const{
    return strlen(_pstr);
}

//String转c_str
const char* String::c_str() const{
    return _pstr;
}

bool operator==(const String &lhs, const String &rhs){
    return !strcmp(lhs._pstr,rhs._pstr);
}

bool operator!=(const String &lhs, const String &rhs){
    return strcmp(lhs._pstr,rhs._pstr);
}

bool operator<(const String &lhs, const String &rhs){
    return strcmp(lhs._pstr,rhs._pstr)<0;
}

bool operator>(const String &lhs, const String &rhs){
    return strcmp(lhs._pstr,rhs._pstr)>0;
}

bool operator<=(const String &lhs, const String &rhs){    
    return strcmp(lhs._pstr,rhs._pstr)<=0;
}
bool operator>=(const String &lhs, const String &rhs){
    
    return strcmp(lhs._pstr,rhs._pstr)>=0;
}

std::ostream &operator<<(std::ostream &os, const String &s){
    if(s._pstr){
        os<<s._pstr;
    }
    return os;
}

std::istream &operator>>(std::istream &is, String &s){
    if(s._pstr){
        delete[] s._pstr;
        s._pstr=nullptr;
    }

    is>>s._pstr;
    return is;
    
}

String operator+(const String &lhs, const String &rhs){
    cout<<"String operator+(const String &lhs, const String &rhs)"<<endl;
    String temp(lhs);
    temp+=rhs;
    return temp;
}

String operator+(const String &lhs, const char *rstr){
    cout<<"String operator+(const String &lhs, const char *rhs)"<<endl;
    String temp(lhs);
    temp += rstr;
    return temp;
}

String operator+(const char *lstr,const String &rhs){
    cout << "String operator+(const char*lstr, const String &rhs)" << endl;
    String temp(lstr);
    temp += rhs;
    return temp;
}
