#include<iostream>
using namespace std;
class number
{
    int n;
    public:
    number(){
        cout<<0<<" ";
    }
    number(int i):n(i){
        cout<<n<<" ";
    }

};
int main(int argc, char const *argv[])
{
    int i=1;
    number n1();
    number *n2=new number(i++);
    //number *n3;
    new number(i++);
    return 0;
}
