#include<iostream>
using namespace std;
main()
{
    int n;
    cout<<"Enter the no";
    cin>>n;
    int mask=0;
    int m=n;
    if(m==0)
     {
        cout<<"9' complement = 1";
     } 
     else
     {
    while (m!=0)
    {
        mask=(mask<<1)|1;
        m=m>>1;
    }
    int complement=(~n)&mask;
    cout<<"9's complement = "<<complement;
     }
}