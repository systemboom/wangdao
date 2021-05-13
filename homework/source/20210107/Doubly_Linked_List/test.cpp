#include"D_Linked.h"

int main() {
	cout << "测试：\n" << endl;
	List d_link;
	d_link.push_front(1);//头插
	
	d_link .push_back(2);//尾插
	d_link.push_back(3);//尾插

	cout << "打印链表：";
	d_link.display();//打印链表

	cout << "查找data=1：";
	d_link.find(1)?cout<<"查找成功\n"<<endl:cout<<"查找失败\n"<<endl; //在链表中进行查找
	
	cout << "在9后面插入99999：";
	if(d_link.insert(9, 99999))d_link.display();//在指定位置后面插入
	
	cout << "在0后面插入99999：";
	if (d_link.insert(0, 99999))d_link.display();//在指定位置后面插入

	cout << "在4后面插入99999：";
	if (d_link.insert(4, 99999))d_link.display();//在指定位置后面插入

	d_link.erase(99999);//删除一个指定的节点
	cout << "删除99999：";
	d_link.display();//打印链表
	
	d_link.pop_back();//尾删
	cout << "尾删：";
	d_link.display();//打印链表
	
	d_link.pop_front();//头删
	cout << "头删：";
	d_link.display();//打印链表

	return 0;

}
