#include"Dictionary.h"
int main(void)
{
	clock_t start, finish;
	double time_length;

	start = clock();
	//start
	Dictionary w;
	w.read("The_Holy_Bible.txt");
	w.store("statics_alphabetical.txt");
	//w.store("statics_frequency.txt", 2);
	//finish
	finish = clock();
	time_length = (double)(finish - start) / CLOCKS_PER_SEC;//��������ʱ�̵Ĳ��������е�ʱ��
	cout << "Runtime:" << time_length << " second." << endl;
	return 0;
}

