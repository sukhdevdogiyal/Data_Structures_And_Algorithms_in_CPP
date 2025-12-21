// 70. Climbing Stairs
// two method 1. Not optimal 2. optimal using DP

// Method 1

#include <iostream>
using namespace std;
int climbStairs(int n)
{

    // Not Optimal solution slove using DP
    // base case
    if (n == 1)
        return 1;
    if (n == 0)
        return 1;
    return climbStairs(n - 1) + climbStairs(n - 2);
}
int main(int argc, char const *argv[])
{
    int n = 0;
    cout<<"Total no. of ways to climb to the top = "<<climbStairs(n)<<endl;
    n = 1;
    cout<<"Total no. of ways to climb to the top = "<<climbStairs(n)<<endl;
    n = 2;
    cout<<"Total no. of ways to climb to the top = "<<climbStairs(n)<<endl;
    n = 10;
    cout<<"Total no. of ways to climb to the top = "<<climbStairs(n)<<endl;
    
    // n=45 is TLE case. It slove DP
    //n = 45;
    //cout<<"Total no. of ways to climb to the top = "<<climbStairs(n)<<endl;
    return 0;
}
