#include"String.h"
int main()
{
    String str1;
    cout<<"str1="<<str1<<endl<<endl;

    String str2="hello world";
    cout<<"str2="<<str2<<endl<<endl;

    str1=str2;
    cout<<"str1=str2:"<<str1<<endl<<endl;
    
    cout<<"str1+str2:"<<str1+str2<<endl<<endl;
    
    cout<<"str2+wangdao:"<<str2+"wangdao"<<endl<<endl;

    cout<<"dalao+str2"<<"dalao"+str2<<endl<<endl;

    return 0;
}

