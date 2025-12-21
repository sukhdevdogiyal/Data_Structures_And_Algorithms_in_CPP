#include <iostream>
using namespace std;
int fact(int n)
{
    // base case
    if (n==0)
    {
        return 1;
    }
    //recursive relation
    int sp = fact(n-1);
    int bp = n*sp;
    return bp;
    
}
int main(int argc, char const *argv[])
{
    int n = 5;
    cout << "Factorial of " << n << " is = " << fact(n);
    return 0;
}
