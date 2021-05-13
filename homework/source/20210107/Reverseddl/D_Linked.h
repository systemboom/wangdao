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

	bool push_front(int data);//在头部进行插入

	bool push_back(int data);//在尾部进行插入

	bool pop_front();//在链表头部进行删除

	bool pop_back();//在链表的尾部进行删除

	Node* find(int data);//在链表中进行查找

	bool insert(int pos, int data);//在指定位置后面插入pos

	void display() const; //打印链表

	void erase(int data);//删除一个指定的节点			 		
	
	void swap(Node* &l, Node* &r);
	
	void Reverse();
private:
	int    _size;
	Node * _head;
	Node * _tail;
	
};
#endif