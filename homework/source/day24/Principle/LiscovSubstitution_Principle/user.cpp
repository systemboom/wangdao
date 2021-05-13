#include<iostream>
using std::cout;
using std::endl;

#include<string>
using std::string;

class User{
public:
    User(const string &name):_name(name),_score(0){}
    
    void consume(float delta){
        _score+=delta;
    cout << "User_score : " << _score << endl;
    }
protected:
    string _name;
    float _score;
};

class VipUser
:public User{
public:
    VipUser(const string & name):User(name),_discount(0.9){
        _score=1000;
    }
    void consume2(float delta){
        if(_score > 1000) {
			_discount = 0.9;
		} else if( _score > 5000) {
			_discount = 0.8;
		} else if( _score > 10000) {
			_discount = 0.7;
		} else {
			_discount = 1;
		}
        float tmp = _discount * delta;
        consume(tmp);
		cout << "VipUser_score : " << _score << endl;
    }
protected:
    float _discount;
};

void test0(){
    User user("哩哩老师");
    user.consume(1100);

    VipUser vipuser("泥鳅老师");
    vipuser.consume(100);
    vipuser.consume2(100);
}
int main(){
    test0();
    return 0;
}
