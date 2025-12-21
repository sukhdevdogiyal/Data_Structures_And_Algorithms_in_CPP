// 2089. Find Target Indices After Sorting Array

#include <iostream>
#include <vector>
using namespace std;

vector<int> targetIndices(vector<int> &nums, int target)
{
    int min = 0;
    int counttargert = 0;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            counttargert++;
        }
        else if (nums[i] < target)
        {
            min++;
        }
    }
    for (int i = 0; i < counttargert; i++)
    {
        ans.push_back(min + i);
    }
    return ans;
}

int main()
{
    // vector<int>nums = {1,2,5,2,3};
    // vector<int>nums = {1,2,5,2,3};
    vector<int> nums = {1, 2, 5, 2, 3};
    // vector<int>nums = {};
    // int target = 2;
    int target = 3;
    // int target = 5;
    vector<int> ans = targetIndices(nums, target);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
