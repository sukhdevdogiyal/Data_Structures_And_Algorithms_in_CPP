#include<iostream>
using namespace std;
int bit(int n)
 {
    int count =0;
    while(n!=0)
    {
        if (n&1==1)
        {
            count++;

        }
        n=n>>1;
    }
    return count;
    
 }
int ans(int a,int b)
   {
    return (bit(a)+bit(b));
   }
main()
{
    int a,b;
    cout<<"Enter the two number ";
    cin>>a>>b;
    int bits=ans(a,b);
    cout<<"Total no of set bite in a & b = "<<bits;
}