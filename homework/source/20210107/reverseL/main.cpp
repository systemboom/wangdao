#include<iostream>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

void reverseList(LinkList &L) {
	if (L->next&&L->next->next) {
		LNode *p = L->next->next;
		LNode *cur;
		L->next->next = nullptr;
		while (nullptr != p) {
			cur = L->next;
			L->next = p;
			p = p->next;
			L->next->next = cur;
		}
	}
		
}
void init(LinkList &L) {
//头插
	L =new LNode();//建立头结点
	L->next = nullptr;
	int i=1;
	while (10!=i){
		LNode *p = new LNode();
		p->data = i++;
		
		p->next = L->next;
		L->next = p;
	}
	
	
}
void print(LinkList L) {
	ios::sync_with_stdio(false); cin.tie(0);
	LNode *p = L->next;
	while (p != nullptr)
	{
		if (p->next != nullptr)
			cout << p->data;
		else
			cout << p->data;
		p = p->next;
	}
	cout << endl;
}
int main()
{
	LinkList L;
	init(L);
	print(L);
	reverseList(L);
	print(L);
	return 0;
}