#include"D_Linked.h"

int main() {
	cout << "���ԣ�\n" << endl;
	List d_link;
	d_link.push_front(1);//ͷ��
	
	d_link .push_back(2);//β��
	d_link.push_back(3);//β��

	cout << "��ӡ����";
	d_link.display();//��ӡ����

	cout << "����data=1��";
	d_link.find(1)?cout<<"���ҳɹ�\n"<<endl:cout<<"����ʧ��\n"<<endl; //�������н��в���
	
	cout << "��9�������99999��";
	if(d_link.insert(9, 99999))d_link.display();//��ָ��λ�ú������
	
	cout << "��0�������99999��";
	if (d_link.insert(0, 99999))d_link.display();//��ָ��λ�ú������

	cout << "��4�������99999��";
	if (d_link.insert(4, 99999))d_link.display();//��ָ��λ�ú������

	d_link.erase(99999);//ɾ��һ��ָ���Ľڵ�
	cout << "ɾ��99999��";
	d_link.display();//��ӡ����
	
	d_link.pop_back();//βɾ
	cout << "βɾ��";
	d_link.display();//��ӡ����
	
	d_link.pop_front();//ͷɾ
	cout << "ͷɾ��";
	d_link.display();//��ӡ����

	return 0;

}
