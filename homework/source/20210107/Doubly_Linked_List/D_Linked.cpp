#include"D_Linked.h"
List::List() {
	cout << "List()\n" << endl;
	Node *p= new Node(); //创建头结点
	p->next = nullptr;
	p->pre = nullptr;
	_head = p;
	_tail = p;
    _size=0;
}//无参构造
List::~List() {

	Node* p1 = _head->next;
	Node* p2 = _head->next;
	while (nullptr!=p2){
		p1 = p2;
		p2 = p2->next;
		delete p1;
		_size--;
	}
	delete _head;
	cout << "~List()" << endl;
}//析构函数

bool List::push_front(int data) {

	Node* p = new Node();
	if (nullptr != p) {
		p->data = data;
		
		if (0 == _size) {
			_head->next = p;
			p->next = nullptr;
			p->pre = _head->next;
			_tail = p;
			_size++;
			return true;
		}
		else {
			p->next = _head->next;
			_head->next->pre = p;

			_head->next = p;
			p->pre = _head->next;


			_size++;
			return true;
		}
		
		
	}
	else {
		puts("申请空间失败");
		return false;
	}
}//在头部进行插入

bool List::push_back(int data) {

	Node* p = new Node();
	if (nullptr != p) {
		p->data = data;
		_tail->next = p;
		p->pre = _tail;

		_tail = p;

		_size++;
		return true;
	}
	else {
		puts("申请空间失败");
		return false;
	}
}//在尾部进行插入

bool List::pop_front() {

	if(0==_size){
		puts("链表已空");
		return false;
	}

	Node *p = _head->next;

	_head->next = p->next;
	p->next->pre = _head->next;

	if (1 == _size) {
		_tail = _head->next;
	}

	delete(p);
	_size--;
	return true;
}//在链表头部进行删除

bool List::pop_back() {
	if (0 == _size) {
		puts("链表已空");
		return false;
	}

	Node *p = _tail->pre;

	delete(_tail);

	_tail = p;
	_tail->next = nullptr;
	_size--;
	return true;
}//在链表的尾部进行删除

Node* List::find(int data) {
//在链表中进行查找
	Node*p = _head->next;
	while (nullptr!=p) {
		if (data == p->data) {
			return p;
		}
		else {
			p = p->next;
		}
	}
	return nullptr;
}

bool List::insert(int pos, int data) {
	if (pos > _size || pos < 0) {
		cout << "非法插入    _size:" <<_size<< endl<<endl;
		return false;
	}
	else if (pos == _size) { //在最后插入
		Node* p = new Node();
		p->data = data;
		p->next = nullptr;
		p->pre = _tail;
		_tail->next=p;
		_tail = p;
		_size++;
		return true;
	}
	else if (0 == pos) { //在第一个结点之前插入
		Node* p = new Node();
		p->data = data;
		p->next = _head->next;
		p->next->pre = p;
		p->pre = _head;
		_head->next = p;
		_size++;
	}
	else {    //在链表中间插入
		Node* p = new Node();
		Node* temp = nullptr;
		temp = _head->next;
		p->data = data;
		for (int i = 0; i < pos; i++) {
			temp=temp->next;//找到要插入的结点位置
		}
		p->pre = temp;
		p->next = temp->next;
		temp->next->pre = p;
		temp->next = p;
		_size++;
	}
	
}//在指定位置后面插入pos

void List::display() const {

	Node *p = _head->next;
	while (p!= nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout <<"    _size："<<_size<< endl<<endl;

}//打印链表

void List::erase(int data) {
	Node* p1 = _head->next;
	Node* p2 = _head->next;
	while (p2 != _tail) {
		p1 = p2;
		p2 = p2->next;
		if (data == p1->data) {
			p1->pre->next = p1->next;
			p1->next->pre = p1->pre;
			delete p1;
			_size--;
		}
	}
	if (data == _tail->data) {
		_tail->pre->next = nullptr;
		p1 = _tail;
		_tail = _tail->pre;
		_size--;
		delete p1;
	}

	//Node *p = find(data);
	//if (nullptr !=p ) {
	//	if (p == _tail) {
	//		p->pre->next = nullptr;
	//		_tail = p->pre;
	//		delete p;
	//	}else {
	//		p->pre->next = p->next;
	//		p->next->pre = p->pre;
	//		delete p;
	//	}
	//	_size--;
	//}

}//删除一个指定的节点
