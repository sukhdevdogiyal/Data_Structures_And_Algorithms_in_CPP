// leetcode 198. House Robber
// https://leetcode.com/problems/house-robber/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Bottom up DP with space optimization
int rob(vector<int> &nums)
{
    int prev2 = nums[0];

    if (nums.size() == 1)
        return prev2;

    int prev1 = max(nums[1], nums[0]);

    for (int i = 2; i < nums.size(); i++)
    {
        int incl = prev2 + nums[i];
        int excl = prev1;

        // update prev2 variable
        prev2 = prev1;
        prev1 = max(incl, excl);
    }
    return prev1;
}
// top down dp
int solve(int n, vector<int> &nums, vector<int> &dp)
{
    // out of bound
    if (n < 0)
        return 0;
    // base case
    if (n == 0)
        return nums[0];
    // alredy comput result
    if (dp[n] != -1)
        return dp[n];
    // include current element
    int incl = nums[n] + solve(n - 2, nums, dp); // n-2 means cuurent element add then adjacent element not add
    // exclude current element
    int excl = solve(n - 1, nums, dp);           // n-1 means curr not add adjacent element add
    return dp[n] = max(incl,excl);
}
int rob1(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(n-1, nums, dp);
}
int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};

    cout << "Maximum amount that can be robbed: "
         << rob(nums) << endl;
    cout << "Maximum amount that can be robbed: "
         << rob1(nums) << endl;

    return 0;
}