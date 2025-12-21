#include<iostream>
#include<limits.h>
#include<float.h>
using namespace std;
int main(int argc, char const *argv[])
{
    cout<<"Ranage of int is : "<<INT_MIN<<" To "<<INT_MAX;
    cout<<"\nRanage of FLOAT is : "<<FLT_MIN<<" To "<<FLT_MAX;
    cout<<"\nRanage CHAR is : "<<CHAR_MIN<<" To "<<CHAR_MAX;
    int a=2147483648;
    cout<<"\na = "<<a;
    a=4294967295;
    cout<<"\na = "<<a;
    unsigned int b=4294967295;
    cout<<"\nb = "<<b<<endl;
    int c = cin.get();
    cout<<"\nc = "<<c;
    return 0;
}
