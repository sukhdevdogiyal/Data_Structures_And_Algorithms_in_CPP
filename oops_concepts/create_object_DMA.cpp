#include<iostream>
using namespace std;

class test
{
    public:
    int a;
};
 
int main(int argc, char const *argv[])
{
    test *t1 = new test();
    t1->a=34;
    cout<<"a = "<<(*t1).a<<endl;
    return 0;
}
