#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int mini = INT_MAX;

    for (int i = 1; i * i <= n; i++)
    {
        mini = min(mini, solve(n - i * i, dp));
    }

    return dp[n] = mini + 1;
}

int solveTab(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    return dp[n];
}

int numSquares(int n)
{
    vector<int> dp(n + 1, -1);

    int memoAns = solve(n, dp);
    int tabAns = solveTab(n);

    cout << "Minimum number of perfect squares" << endl;
    cout << "Memoization Answer : " << memoAns << endl;
    cout << "Tabulation Answer  : " << tabAns << endl;

    return tabAns;
}

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    numSquares(n);

    return 0;
}