#include<iostream>
using namespace std;
void fun(int &a)
{
    a++;
    cout <<"\nAddress of function variable &a = "<<&a<<endl;
}
int &fun1()
{
    int a=93;
    cout<< "\nInside fun1 a = "<<a<<endl;
    return a;
}
int main(int argc, char const *argv[])
{
    int a =33;
    int &b =a;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"&a = "<<&a<<endl;
    cout<<"&b = "<<&b<<endl;
    
    cout<<endl;
    //in function
    int c=93;
    cout<<"Address of main variable &c = "<<&c<<endl;
    cout<<"Befor function call c = "<<c<<endl;
    fun(c);
    cout<<"\nAfter function call c = "<<c<<endl;
    
    //return reference 
    // int &d=fun1();      //give to warning: reference to local variable
    //cout<<"d = "<<d<<endl;
    //cout<<"&d = "<<&d<<endl;

    
    return 0;
}
