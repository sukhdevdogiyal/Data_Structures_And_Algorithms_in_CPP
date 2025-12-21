#include<iostream>
using namespace std;
int factorial(int n)
{
    int fact=1;
    for (int i = 1; i <=n; i++)
    {
        fact=fact*i;

    }
    return fact;
    
}
int ncr(int n,int r)
{
    int ncr = factorial(n)/(factorial(r)*factorial(n-r));
    return ncr;
}
main()
{
    int n,r;
    cout<<"Enter the n";
    cin>>n;
    cout <<"Enter the r";
    cin>>r;
    int ans=ncr(n,r);
    cout<<"nCr = "<<ans;

}