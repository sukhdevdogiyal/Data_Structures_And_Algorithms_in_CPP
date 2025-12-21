#include<iostream>
using namespace std;
main()
{
    int a=2;
    cout<<"a="<<a<<endl;
    {
        cout<<"In side body"<<endl;
        int a=9;
        cout<<"a="<<a<<endl;
    }
    cout<<"Out side body"<<endl;
    cout<<"a="<<a<<endl;
}