#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    char ch[]="abcd";
    cout<<"sizeof(ch) = "<<sizeof(ch)<<endl;
    cout<<"ch = "<<ch<<endl;
    
    char *c=&ch[0];
    cout<<"c = "<<c<<endl;
    cout<<"*c = "<<*c<<endl;
    
    char ch1='8';
    cout<<"ch1 = "<<ch1<<endl;
    char *c1=&ch1;
    cout<<"c1 = "<<c1<<endl;//8garbage
    cout<<"c1+6 = "<<c1+6<<endl;//garbage value
    cout<<"*c1 = "<<*c1<<endl;

    // not use this method
    // char *c2 = "abc";
    return 0;
}
