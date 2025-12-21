// leet code 360
// count ways to reach the n-th stairs
#include<iostream>
using namespace std;
int ways(int n)
{
    // Base case
    if (n<0)
    {
        return 0;
    }
    if (n==0)
    {
        return 1;
    }
    int s1 = ways(n-1);
    int s2 = ways(n-2);
    int bp = s1+ s2;
    return bp;
    
    
}
int main(int argc, char const *argv[])
{
    int n=3;
    cout<<"Count ways to reach the "<<n<<"-th stairs : "<<ways(n);
    return 0;
}
