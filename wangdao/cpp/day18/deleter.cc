#include <stdio.h>
#include <iostream>
#include <memory>
#include <string>


using std::cout;
using std::endl;
using std::unique_ptr;
using std::shared_ptr;
using std::string;

struct FILECloser
{
    void operator()(FILE *fp)
    {
        if(fp)
        {
            fclose(fp);
            cout << "fclose(fp)" << endl;
        }
    }
};
void test()
{
    unique_ptr<FILE, FILECloser> up(fopen("wuhan.txt", "a+"));
    string msg = "hello,world\n";
    fwrite(msg.c_str(), 1, msg.size(), up.get());
    /* fclose(up.get()); */
}
void test1()
{
    shared_ptr<FILE> up(fopen("wuhan1.txt", "a+"), FILECloser());
    string msg = "hello,world\n";
    fwrite(msg.c_str(), 1, msg.size(), up.get());
    /* fclose(up.get()); */
}
int main(int argc, char **argv)
{
    test1();
    return 0;
}


