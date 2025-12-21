#include<iostream>
using namespace std;
void fun(int *p)
{
    cout<<"Inside sizeof(p) = "<<sizeof(p)<<endl;
    
    cout<<"Inside Befor *p = "<<*p<<endl;
    *p=*p+1;
    cout<<"Inside After *p = "<<*p<<endl;
    
    cout<<"Inside Befor ptr = "<<p<<endl;
    p=p+1;
    cout<<"Inside After ptr = "<<p<<endl;
    
    cout<<"Inside After *p = "<<*p<<endl;
}
int main(int argc, char const *argv[])
{
    int a=990;
    int *ptr=&a;
    cout<<"sizeof(ptr) = "<<sizeof(ptr)<<endl;
    cout<<"Befor *ptr = "<<*ptr<<endl;
    cout<<"Befor ptr = "<<ptr<<endl;
    fun(ptr);
    cout<<"After ptr = "<<ptr<<endl; // not update ptr
    cout<<"After *ptr = "<<*ptr<<endl; // value is change
    return 0;
}
