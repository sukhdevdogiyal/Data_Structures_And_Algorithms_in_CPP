// Leetcode
// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/description/
// optimal using DP

#include <iostream>
#include <vector>
using namespace std;
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
    cout << "Stairs : " << n << endl;
    cout << "Total no. of ways to climb to the top = " << climbStairs(n) << endl;
    cout << endl;

    n = 1;
    cout << "Stairs : " << n << endl;
    cout << "Total no. of ways to climb to the top = " << climbStairs(n) << endl;
    cout << endl;

    n = 2;
    cout << "Stairs : " << n << endl;
    cout << "Total no. of ways to climb to the top = " << climbStairs(n) << endl;
    cout << endl;

    n = 10;
    cout << "Stairs : " << n << endl;
    cout << "Total no. of ways to climb to the top = " << climbStairs(n) << endl;
    cout << endl;

    // n = 45 causes TLE in the pure recursive solution.
    // Memoization reduces the complexity to O(n).
    n = 45;
    cout << "Total no. of ways to climb to the top = " << climbStairs(n) << endl;
    return 0;
}
