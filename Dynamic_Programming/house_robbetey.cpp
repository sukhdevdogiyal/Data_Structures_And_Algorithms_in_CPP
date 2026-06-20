// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/description/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums)
{
    if (nums.size() == 1)
        return nums[0];

    int n = nums.size();

    // Case 1: Include first house, exclude last
    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n - 1; i++)
    {
        int incl = nums[i] + prev2;
        int excl = prev1;

        prev2 = prev1;
        prev1 = max(incl, excl);
    }

    int first = prev1;

    // Case 2: Exclude first house, include last
    prev2 = 0;
    prev1 = nums[1];

    for (int i = 2; i < n; i++)
    {
        int incl = nums[i] + prev2;
        int excl = prev1;

        prev2 = prev1;
        prev1 = max(incl, excl);
    }

    int last = prev1;

    return max(first, last);
}

int main()
{
    vector<int> nums = {2, 3, 2};

    cout << "Maximum amount that can be robbed: "
         << rob(nums) << endl;
    nums = {1,2,3,1};

    cout << "Maximum amount that can be robbed: "
         << rob(nums) << endl;
    nums = {1,2,3};

    cout << "Maximum amount that can be robbed: "
         << rob(nums) << endl;

    return 0;
}