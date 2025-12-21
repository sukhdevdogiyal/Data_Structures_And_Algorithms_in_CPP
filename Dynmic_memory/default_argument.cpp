#include<iostream>
using namespace std;
int sum(int a,int b,int c=0) // hamesa default argrument parameter list ke right most me likha te hai
{
    return a+b+c;
}
// int add(int a=9,int b)  // give error :default argument missing for parameter 2 of 'int add(int, int)'
// {
//     return a+b;
// }
int main()
{
    int a=3;int b=34;int c=99;
    cout<<"sum of two number use default argument"<<endl;
    cout<<"sum : "<<sum(a,b)<<endl;
    cout<<"sum : "<<sum(a,b,c)<<endl;
}