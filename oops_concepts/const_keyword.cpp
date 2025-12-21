#include<iostream>
using namespace std;

// const parameter function
void fun(const int &a)
{
    cout<<"Befor change a = "<<a<<endl;
    //a=99;
    cout<<"Give error const variable read only"<<endl;
    
}

// const in class
class test
{
    const int a=88; // this is curruct
    int b;
    public:
    test(int v):a(v)
    {
        //a=99;
        b=3;
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
    }
    void fun() const
    {
        // b=9;
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
       cout<<"const function can not change any non-mutable member"<<endl;
    }
    void fun1()
    {
        cout<<"Call fun1"<<endl;
    }
};
int main(int argc, char const *argv[])
{
    cout<<"Simple Variable"<<endl;
    int a=4;
    cout<<"Befor change a = "<<a<<endl;
    a=3;
    cout<<"After change a = "<<a<<endl;
    
    cout<<endl<<"Const variable"<<endl;
    const int b=99;
    cout<<"Befor change a = "<<b<<endl;
    //b=3;
    cout<<"Give error const variable read only"<<endl;
    cout<<"After change a = "<<b<<endl;
    
    cout<<endl<<"Const variable with Pointer"<<endl;
    int z=33;
    int y=44;
    const int *c=&z;
    cout<<"Befor change *c = "<<*c<<endl;
    c=&y;
    cout<<"After change *c = "<<*c<<endl;
    // *c=99;
    cout<<"Give error const variable read only"<<endl;
    
    cout<<endl<<"Const variable with Pointer"<<endl;
    int* const d=&z;
    cout<<"Befor change *d = "<<*d<<endl;
    *d=99;
    cout<<"After change *d = "<<*d<<endl;
    //d=&y;
    cout<<"Give error const variable read only"<<endl;
    
    // const function
    cout<<endl<<"const function parameter"<<endl;
    fun(a);
    
    // const class
    cout<<endl<<"const in class"<<endl;
    test t1(66);
    t1.fun();
    
    cout<<endl<<"const object"<<endl;
    const test t2(34);
    cout<<"call const function"<<endl;
    t2.fun();
    cout<<"Can not call non const function"<<endl;
   // t2.fun1();

    
    return 0;
}
