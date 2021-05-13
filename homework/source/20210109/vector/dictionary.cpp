#include"dictionary.h"
void Dictionary::read(const std::string & filename) {
	std::ifstream ifs(filename.c_str());
	std::string str;
	if (!ifs.good()) {      // bool good();�����ǰ��û�з������󣬺���good()����true �����򷵻�false
		cerr << ">> ifstream open file error!\n";
		return;
	}

	cout << "start to read" << endl;
	while (getline(ifs, str)) {//���ж��룬getline���Զ����ո���ַ�������'\n'������'\n'�����뻺��������ֱ��ȥ��
		stringstream ss(str);

		//stringstream��ͬʱ����֧��C���Ĵ����������������,��string�����ȡ�ַ����ַ���,���Դ��������һ���а�������ַ��Լ��ո���ַ���
		string wd;

		while (ss >> wd) { //������ʶ���
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
