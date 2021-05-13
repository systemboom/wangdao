#include"D_Linked.h"

int main() {
	cout << "²âÊÔ£º\n" << endl;
	List d_link;
	
	int i = 0;
	while (10 != i) {
		d_link.push_back(++i);
	}
	d_link.display();

	d_link.Reverse();

	d_link.display();
	return 0;

}