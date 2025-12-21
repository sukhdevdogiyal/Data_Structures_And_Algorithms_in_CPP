#include <iostream>
using namespace std;
int *fun()
{
    int x=29;
    cout<<"&x = "<<&x<<endl;;
    return &x;
}
int main(int argc, char const *argv[])
{
    int *p1;
    {
        int a = 9;
        p1 = &a;
        cout<<"inside p1 : "<<p1<<endl;
    }
    // here p1 is dangling
    cout<<"outside p1 : "<<*p1<<endl;
    int *p2=fun();
    //p2 dangling pointer
    cout<<"p2 = "<<p2<<endl;
    
    return 0;
}
