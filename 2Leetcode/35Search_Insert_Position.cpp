// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/

#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int mid = -1;
    int s = 0, e = nums.size() - 1;
    int ans = e + 1;

    while (s <= e)
    {
        mid = s + (e - s) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[mid] > target)
        {
            e = mid - 1;
            ans = mid;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}

int main()
{

    // Test Case 1
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    cout << "Test Case 1: "
         << searchInsert(nums1, target1) << endl;

    // Test Case 2
    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    cout << "Test Case 2: "
         << searchInsert(nums2, target2) << endl;

    // Test Case 3
    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    cout << "Test Case 3: "
         << searchInsert(nums3, target3) << endl;

    return 0;
}
