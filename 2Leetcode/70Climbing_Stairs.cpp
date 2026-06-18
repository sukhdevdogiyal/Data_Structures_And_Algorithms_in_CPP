// 70. Climbing Stairs
// two method 1. Not optimal 2. optimal using DP

// Method 1

#include <iostream>
#include <vector>
using namespace std;
int climbStairs1(int n)
{

    // Not Optimal solution slove using DP
    // base case
    if (n == 1)
        return 1;
    if (n == 0)
        return 1;
    return climbStairs1(n - 1) + climbStairs1(n - 2);
}
int solve1(int n, vector<int> &dp)
{
    // If we are already at the top, count it as one valid way
    if (n == 0)
        return 1;

    // Only one step left, so there is exactly one way
    if (n == 1)
        return 1;

    // Return previously computed result
    if (dp[n] != -1)
        return dp[n];

    // Number of ways = ways from (n-1) stairs + ways from (n-2) stairs
    dp[n] = solve1(n - 1, dp) + solve1(n - 2, dp);

    return dp[n];
}

int climbStairs(int n)
{
    // DP array to store computed results
    vector<int> dp(n + 1, -1);

    // Solve using memoization
    return solve1(n, dp);
}
int main(int argc, char const *argv[])
{
    int n = 0;
    cout << "Total no. of ways to climb to the top = " << climbStairs1(n) << endl;
    cout << "Total no. of ways to climb to the top = " << climbStairs(n) << endl;
    cout << endl;
    n = 1;
    cout << "Total no. of ways to climb to the top = " << climbStairs1(n) << endl;
    cout << "Total no. of ways to climb to the top = " << climbStairs(n) << endl;
    cout << endl;

    n = 2;
    cout << "Total no. of ways to climb to the top = " << climbStairs1(n) << endl;
    cout << "Total no. of ways to climb to the top = " << climbStairs(n) << endl;
    cout << endl;

    n = 10;
    cout << "Total no. of ways to climb to the top = " << climbStairs1(n) << endl;
    cout << "Total no. of ways to climb to the top = " << climbStairs(n) << endl;
    cout << endl;

    // n=45 is TLE case. It slove DP
    n = 45;
    // cout<<"Total no. of ways to climb to the top = "<<climbStairs1(n)<<endl;
    cout << "Total no. of ways to climb to the top = " << climbStairs(n) << endl;
    return 0;
}
