// 377. Combination Sum IV
// https://leetcode.com/problems/combination-sum-iv/description/
// DP
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums, int target, vector<int> &dp)
{
    if (target < 0)
        return 0;

    if (target == 0)
        return 1;

    if (dp[target] != -1)
        return dp[target];

    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        ans += solve(nums, target - nums[i], dp);
    }

    return dp[target] = ans;
}

int combinationSum4(vector<int> &nums, int target)
{
    vector<int> dp(target + 1, -1);
    return solve(nums, target, dp);
}

int main()
{
    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    int target1 = 4;
    cout << "Test Case 1: " << combinationSum4(nums1, target1) << endl;

    // Test Case 2
    vector<int> nums2 = {2, 4, 6};
    int target2 = 8;
    cout << "Test Case 2: " << combinationSum4(nums2, target2) << endl;

    // Test Case 3
    vector<int> nums3 = {1, 2};
    int target3 = 5;
    cout << "Test Case 3: " << combinationSum4(nums3, target3) << endl;

    // Test Case 4
    vector<int> nums4 = {9};
    int target4 = 3;
    cout << "Test Case 4: " << combinationSum4(nums4, target4) << endl;

    return 0;
}