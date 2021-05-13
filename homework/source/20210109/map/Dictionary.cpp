#include"Dictionary.h"
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

			_dict[wd]++;

		}

	}
	ifs.close();
}
void Dictionary::store(const std::string & filename) {
	ofstream ofs(filename);
	if (!ofs.good()) {
		cerr << ">> ofstream open file error!\n";
		return;
	}
	for (auto it : _dict) {
		ofs << it.first<< " " << it.second<< endl;
	}
	ofs.close();
}
