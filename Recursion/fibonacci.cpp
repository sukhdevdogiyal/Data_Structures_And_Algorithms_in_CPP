#include<iostream>
using namespace std;
int fib(int n)
{
    // base case
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }
    int sp1 = fib(n-1);
    //cout<<sp1<<endl;
    int sp2 = fib(n-2);
    //cout<<sp2<<endl;
    int sp =sp1+sp2;
    //cout<<sp<<" ";
    return sp;
    
}
int main(int argc, char const *argv[])
{
    int n=10;  // 0 1 1 2 3 5 8 13 21 34 55
    cout<<"Fibonacci Series "<<n<<" Element : "<<fib(n);
    return 0;
}
