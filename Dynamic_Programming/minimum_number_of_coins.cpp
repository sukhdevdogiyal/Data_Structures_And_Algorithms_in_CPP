// Minimum no. of coins
// leet code
// 322. Coin Change
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve1(vector<int> &coins, int amount)
{
    // Base case
    if (amount == 0)
        return 0;

    // Negative amount means no valid solution
    if (amount < 0)
        return INT_MAX;

    int mini = INT_MAX;

    // Try every coin
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solve1(coins, amount - coins[i]);

        if (ans != INT_MAX)            // use of this INT_MAX+1 give overflow
            mini = min(mini, ans + 1); // ans+1 means one more coin required
    }
    return mini;
}
// Time Complexity  : O(n^amount)
// Space Complexity : O(amount)
int coinChangeRec(vector<int> &coins, int amount)
{
    int ans = solve1(coins, amount);

    if (ans == INT_MAX)
        return -1;

    return ans;
}

// TOP DOWN DP (MEMOIZATION)
int solveDP(vector<int> &coins, int amount, vector<int> &dp)
{
    if (amount == 0)
        return 0;

    if (amount < 0)
        return INT_MAX;

    if (dp[amount] != -1)
        return dp[amount];

    int mini = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solveDP(coins, amount - coins[i], dp);

        if (ans != INT_MAX)
            mini = min(mini, ans + 1);
    }

    return dp[amount] = mini;
}
// Time:  O(amount × coins)
// Space: O(amount)
int coinChangeDP(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, -1);

    int ans = solveDP(coins, amount, dp);

    return (ans == INT_MAX) ? -1 : ans;
}
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Coins: {1,2,5}, Amount: 11" << endl;

    cout << "Recursion Answer: "
         << coinChangeRec(coins, amount) << endl;

    cout << "DP (Memoization) Answer: "
         << coinChangeDP(coins, amount) << endl;

    cout << endl;

    coins = {2};
    amount = 3;

    cout << "Coins: {2}, Amount: 3" << endl;

    cout << "Recursion Answer: "
         << coinChangeRec(coins, amount) << endl;

    cout << "DP (Memoization) Answer: "
         << coinChangeDP(coins, amount) << endl;

    return 0;
}