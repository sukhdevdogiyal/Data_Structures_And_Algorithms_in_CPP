#include <iostream>
#include <vector>
using namespace std;
int solve1(int n, vector<int> &dp)
{
    // Base cases: F(0)=0, F(1)=1
    if (n == 0 || n == 1)
        return n;

    // Return already computed result
    if (dp[n] != -1)
        return dp[n];

    // Compute and store result for future use
    dp[n] = solve1(n - 1, dp) + solve1(n - 2, dp);

    return dp[n];
}
// Top down
// recursion and memorization
// T.C. = O(n)
// S.C. = O(n)
int fib(int n)
{
    // Create DP array and initialize all values as uncomputed (-1)
    vector<int> dp(n + 1, -1);

    // Compute nth Fibonacci number using memoization
    return solve1(n, dp);
}

// Bottom Up (Tabulation)
// T.C. = O(n)
// S.C. = O(n)
int fib2(int n)
{
    // Handle base case separately
    if (n == 0)
        return 0;

    // Create DP table
    vector<int> dp(n + 1, -1);

    // Initialize first two Fibonacci numbers
    dp[0] = 0;
    dp[1] = 1;

    // Fill the table from bottom to top
    for (int i = 2; i <= n; i++)
    {
        // Current Fibonacci number is sum of previous two
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Return the answer stored at index n
    return dp[n];
}
// Bottom Up (Tabulation)
// Space Optimized
// T.C. = O(n)
// S.C. = O(1)
int fib3(int n)
{
    // Base case
    if (n == 0)
        return 0;

    // Store last two Fibonacci numbers
    int prev2 = 0;
    int prev1 = 1;

    // Compute Fibonacci numbers iteratively
    for (int i = 2; i <= n; i++)
    {
        // Calculate current Fibonacci number
        int cur = prev1 + prev2;

        // Update previous values for next iteration
        prev2 = prev1;
        prev1 = cur;
    }

    // prev1 contains the nth Fibonacci number
    return prev1;
}
int main(int argc, char const *argv[])
{
    int n = 7;
    cout << n << "th fibonacci no. : " << fib(n) << endl;
    cout << n << "th fibonacci no. : " << fib2(n) << endl;
    cout << n << "th fibonacci no. : " << fib3(n) << endl;
    cout << endl;
    n = 0;
    cout << n << "th fibonacci no. : " << fib(n) << endl;
    cout << n << "th fibonacci no. : " << fib2(n) << endl;
    cout << n << "th fibonacci no. : " << fib3(n) << endl;
    cout << endl;
    return 0;
}
