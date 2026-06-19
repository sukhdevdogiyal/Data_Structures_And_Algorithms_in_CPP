// 746. Min Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/description/

#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int> &cost, vector<int> &dp)
{
    // Base case:
    // Cost to reach step 0 or step 1 is the cost of that step itself
    if (n == 0 || n == 1)
        return cost[n];

    // Return already computed result
    if (dp[n] != -1)
        return dp[n];

    // Minimum cost to reach the previous step
    int prev1 = solve(n - 1, cost, dp);

    // Minimum cost to reach two steps below
    int prev2 = solve(n - 2, cost, dp);

    // Choose the cheaper path and add current step cost
    dp[n] = min(prev1, prev2) + cost[n];

    return dp[n];
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();

    // DP array for memoization
    vector<int> dp(n, -1);

    // We can reach the top either from the last step
    // or the second-last step, whichever is cheaper
    return min(solve(n - 1, cost, dp),
               solve(n - 2, cost, dp));
}

// Bottom Up DP (Tabulation)
// Space Optimized
// T.C. = O(n)
// S.C. = O(1)
int minCostClimbingStairs1(vector<int> &cost)
{
    int n = cost.size();

    // Base costs to reach step 0 and step 1
    int prev2 = cost[0];
    int prev1 = cost[1];

    // Compute minimum cost for each step
    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev1, prev2);

        // Update previous states
        prev2 = prev1;
        prev1 = curr;
    }

    // Reach the top from either last or second-last step
    return min(prev1, prev2);
}

int main()
{
    vector<int> cost1 = {10, 15, 20};
    cout << "Cost = {10, 15, 20}" << endl;
    cout << "Minimum Cost = "
         << minCostClimbingStairs(cost1) << endl;
    cout << "Minimum Cost = "
         << minCostClimbingStairs1(cost1) << endl;
    cout << endl;

    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Cost = {1,100,1,1,1,100,1,1,100,1}" << endl;
    cout << "Minimum Cost = "
         << minCostClimbingStairs(cost2) << endl;
    cout << "Minimum Cost = "
         << minCostClimbingStairs1(cost2) << endl;
    cout << endl;

    return 0;
}