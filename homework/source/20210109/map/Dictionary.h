#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include <time.h>
#include <sstream>
#include<iostream>
#include<fstream>
//#include<vector>
#include<map>
#include<string>
#include<cstring>
#include <algorithm>

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::cerr;
using std::stringstream;

class Dictionary {
public:
	//......
	void read(const std::string & filename);
	void store(const std::string & filename);
	//......
	map<string, int> _dict;
};

#endif