#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include <time.h>
#include <sstream>
#include<iostream>
#include<fstream>
#include<vector>
//#include<unordered_map>
#include<string>
#include<cstring>
#include <algorithm>

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::string;
using std::vector;
//using std::unordered_map;
using std::cerr;
using std::stringstream;




struct Word
{
	string _word;
	int _frequency;
};

static bool cmp1(Word a, Word b) {
		return a._word < b._word;
}
static bool cmp2(Word a, Word b) {
	return a._frequency > b._frequency;
}
class Dictionary{
public:
	//......
	void read(const std::string & filename);
	void store(const std::string & filename, int cmp);//另外一个文件
private:
	//......
	vector<Word> _dict;
};

#endif