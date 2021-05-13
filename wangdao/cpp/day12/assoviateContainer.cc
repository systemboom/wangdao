#include<iostream>
#include<set>
#include<map>

using std::cout;
using std::endl;
using std::set;
using std::map;

void test1(){
   /* set特征 */
   /* 1、key值唯一，不能存放关键字相同的元素 */
   /* 2、默认情况下，set按照key从小到大排列 */
    set<int> numbers{1,5,90,45,2};
    numbers.insert(1);
    numbers.insert(2);
    for(auto &elem:numbers){
        cout<<elem<<" ";
    }
    cout<<endl;
}

int main(){
    test1();
    return 0;
}
