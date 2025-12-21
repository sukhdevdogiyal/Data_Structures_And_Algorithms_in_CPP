#include<iostream>
using namespace std;
void fun(int **);
int main()
{
    /*
    int i=8;
    int *p1=&i;
    int **p2=&p1;
    cout<<"\nValue of variable : "<<endl;
    cout<<"i = "<<i<<endl;
    cout<<"*p1 = "<<*p1<<endl;
    cout<<"**p2 = "<<**p2<<endl;

    cout<<"\nAddress of variable : "<<endl;
    cout<<"&i = "<<&i<<endl;
    cout<<"p1 = "<<p1<<endl;
    cout<<"*p2 = "<<*p2<<endl;
    
    cout<<"\nAddress of single pointer : "<<endl;
    cout<<"&p1 = "<<&p1<<endl;
    cout<<"p2 = "<<p2<<endl;

    cout<<"\nAddress of double pointer : "<<endl;
    cout<<"&p2 = "<<&p2<<endl;

    cout<<"\nChange value using variable : "<<endl;
    i=99;
    cout<<"After change Value of variable : "<<endl;
    cout<<"i = "<<i<<endl;
    cout<<"*p1 = "<<*p1<<endl;
    cout<<"**p2 = "<<**p2<<endl;
    
    cout<<"\nChange value using first pointer : "<<endl;
    *p1=34;
    cout<<"After change Value of variable : "<<endl;
    cout<<"i = "<<i<<endl;
    cout<<"*p1 = "<<*p1<<endl;
    cout<<"**p2 = "<<**p2<<endl;
    
    cout<<"\nChange value using double pointer : "<<endl;
    **p2=3343;
    cout<<"After change Value of variable : "<<endl;
    cout<<"i = "<<i<<endl;
    cout<<"*p1 = "<<*p1<<endl;
    cout<<"**p2 = "<<**p2<<endl;
    */


    cout<<"\n\nPointer with function : "<<endl;
    int a=355;
    int *p=&a;
    int **q=&p;
    cout<<&a<<endl;
    cout<<&p<<endl;
    cout<<p<<endl;
    cout<<"Befor Function call value of a = "<<a<<endl<<endl;
    fun(q);
    cout<<"\nAfter Function call value of a = "<<a<<endl;
    cout<<p<<endl;
    
    cout<<**q<<endl;
    cout<<*p;
}
void fun(int **p)
{
    cout<<"Inside Befor value **p = "<<**p<<endl;
    // p=p+2 // no change 
    // *p =*p+1 //  inside *p change
    **p=**p+4;
    

    cout<<"Inside After value **p = "<<**p<<endl;

}