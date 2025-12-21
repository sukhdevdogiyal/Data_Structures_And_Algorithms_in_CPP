#include<iostream>
using namespace std;
int isprime(int n)
{
    for (int i = 2; i <n; i++)
    {
        if (n%i==0)
        {
            return 1;
        }
        
    }
        return 0;
    
}
main()
{
    int n;
    cout<<"Enter the no = ";
    cin>>n;
    if (isprime(n)==1)
    {
        cout<<"Number is Not prime";
    }
    else
    {
        cout<<"Number is Prime";
    }
    
}