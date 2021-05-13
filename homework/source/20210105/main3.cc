#include<iostream>
class Sample
{
private:
	int i;
	static int k;
	public:
	Sample( );
	void Display( );
};
int Sample::k=0;
Sample:: Sample( ) { i=0;k++;}
void  Sample::Display( ){ 
	std::cout<<"i="<<i<<",k="<<k<<std::endl;
}
int main(){ 
 Sample a,b;
a.Display( );
b.Display( );
return 0;
}

