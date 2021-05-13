#ifndef _STRING_H_
#define _STRING_H_

#include<iostream>
using namespace std;
class String
{
public:
	String();
	String(const char *pstr);
	String(const String & rhs);
	String & operator=(const String & rhs);
	~String();

	void print();

private:
	char * _pstr;
};

#endif // !_STRING_H_

