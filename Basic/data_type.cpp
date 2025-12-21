#include<iostream>
using namespace std;
int main()
{
    int a=8;
    cout << "a=" << a <<endl;
    char b='v';
    cout<<"b="<<b<<'\n';
    bool bl=false;
    cout<<"bl:"<<bl<<endl;
    double c=1.333;
    cout<<"c:"<<c<<endl;
    int sizea=sizeof(a);
    cout<<"size of a :"<<sizea<<endl;
    int sizeb=sizeof(b);
    cout<<"size of b :"<<sizeb<<endl;
    int sizebl=sizeof(bl);
    cout<<"size of bl :"<<sizebl<<endl;
    int sizec=sizeof(c);
    cout<<"size of c :"<<sizec<<endl;
    return 0;
} 
