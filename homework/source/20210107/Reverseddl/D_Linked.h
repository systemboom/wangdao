#ifndef D_LINKED_H_
#define D_LINKED_H_
#include<iostream>
using std::cout;
using std::endl;

struct Node
{
	int data;
	Node * pre;
	Node * next;
};

class List
{
public:
	List();
	List(int &n);
	~List();

	bool push_front(int data);//��ͷ�����в���

	bool push_back(int data);//��β�����в���

	bool pop_front();//������ͷ������ɾ��

	bool pop_back();//�������β������ɾ��

	Node* find(int data);//�������н��в���

	bool insert(int pos, int data);//��ָ��λ�ú������pos

	void display() const; //��ӡ����

	void erase(int data);//ɾ��һ��ָ���Ľڵ�			 		
	
	void swap(Node* &l, Node* &r);
	
	void Reverse();
private:
	int    _size;
	Node * _head;
	Node * _tail;
	
};
#endif