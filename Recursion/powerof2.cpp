#include<iostream>
using namespace std;
int power(int n)
{
    cout<<n<<endl;
    if (n==0)
    {
        return 1;
    }
    int smallproblem = power(n-1);
    cout<<n<<endl;
    int bigproblem = 2*smallproblem;
    return bigproblem;
    
}
int main()
{
    int n=3;
    cout<<"2 ki power "<<n<<" is = "<<power(n);
}