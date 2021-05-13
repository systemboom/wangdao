#include"consumer.h"
#include"producer.h"
#include"taskqueue.h"
using namespace wd;

#include <memory>
using std::unique_ptr;


void test0(){

   TaskQueue que(10);
   unique_ptr<Thread> producer(new Producer(que));
   unique_ptr<Thread> consumer(new Consumer(que));

   producer->start();
   consumer->start();

   producer->join();
   consumer->join();


}
int main(){
    test0();
    return 0;
}
