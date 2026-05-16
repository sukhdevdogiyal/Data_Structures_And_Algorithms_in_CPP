// 154. Find Minimum in Rotated Sorted Array II
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/?envType=daily-question&envId=2026-05-16
//  array of length n sorted in ascending order is rotated between 1 and n times
// sorted rotated array nums that may contain duplicates

// T. C. = O(log(n))

#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;
    int last = nums[r];
    while (l < r && nums[l] == last)
        l++;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] > last)
        {
            l = mid + 1;
        }
        else
            r = mid;
    }
    return nums[l];
}
void print(vector<int> &v)
{
    cout << "Array : ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    vector<int> v = {10,1,10,10,10};
    print(v);
    cout << "Minimum Element of this Array : " << findMin(v) << endl;
    v = {2, 2, 2, 0, 1};
    print(v);
    cout << "Minimum Element of this Array : " << findMin(v) << endl;
    v = {4, 5, 6, 7, 0, 1, 4};
    print(v);
    cout << "Minimum Element of this Array : " << findMin(v) << endl;
    v = {2, 2, 2, 2, 2, 2, 2};
    print(v);
    cout << "Minimum Element of this Array : " << findMin(v) << endl;
    return 0;
}
