#include"dictionary.h"
void Dictionary::read(const std::string & filename) {
	std::ifstream ifs(filename.c_str());
	std::string str;
	if (!ifs.good()) {      // bool good();如果当前流没有发生错误，函数good()返回true ，否则返回false
		cerr << ">> ifstream open file error!\n";
		return;
	}

	cout << "start to read" << endl;
	while (getline(ifs, str)) {//按行读入，getline可以读到空格等字符，遇到'\n'结束，'\n'不放入缓存区而是直接去除
		stringstream ss(str);

		//stringstream类同时可以支持C风格的串流的输入输出操作,从string对象读取字符或字符串,可以处理输入的一行中包含多个字符以及空格的字符串
		string wd;

		while (ss >> wd) { //逐个单词读入
			vector<Word>::iterator it;
			for (it = _dict.begin(); it != _dict.end(); ++it) {
				if (wd == (*it)._word) {
					(*it)._frequency++;
					break;
				}
			}
			if (it == _dict.end()) {
				Word newWord;
				newWord._word = wd;
				newWord._frequency = 1;
				_dict.push_back(newWord);
			}

		}

	}
	ifs.close();
}
void Dictionary::store(const std::string & filename,int cmp) {
	ofstream ofs(filename);
	if (!ofs.good()) {
		cerr << ">> ofstream open file error!\n";
		return;
	}
	if (cmp == 1) {
		cout << "alphabetical order" << endl;
		sort(_dict.begin(), _dict.end(), cmp1);
	}
	else {
		cout << "frequency order" << endl;
		sort(_dict.begin(), _dict.end(), cmp2);
	}

	for (auto it : _dict) {
		ofs << it._word << " " << it._frequency << endl;
	}
	ofs.close();
}
