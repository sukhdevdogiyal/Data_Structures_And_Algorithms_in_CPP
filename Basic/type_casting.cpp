#include<iostream>
using namespace std;
int main()
{
    int a='a';
    cout<<"a="<<a<<endl;
    char ch=98;
    cout<<"ch="<<ch<<endl;
    char ch1='98';
    cout<<"ch1="<<ch1<<endl;
      char ch2=1234;//(1234)10=>(10011010010)2 
    cout<<"ch2="<<ch2<<endl;
     char ch3=123456;
    cout<<"ch3="<<ch3<<endl;
   unsigned int b=11;
   cout<<"b="<<b<<'\n';
    unsigned int b1=-11;  //(11)10=(1011)2   2`s complement of 1011=(11111111111111111111111111110101)2=(4294967285)10//
   cout<<"b1="<<b1<<'\n';
   char c;
   c=cin.get();
   cout<<"c="<<c<<endl;
    return 0;
}
