// 153. Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
//  array of length n sorted in ascending order is rotated between 1 and n times

// T. C. = O(log(n))

#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[r])
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
    vector<int> v = {11, 13, 15, 17};
    print(v);
    cout << "Minimum Element of this Array : " << findMin(v) << endl;
    v = {3, 4, 5, 1, 2};
    print(v);
    cout << "Minimum Element of this Array : " << findMin(v) << endl;
    v = {4, 5, 6, 7, 0, 1, 2};
    print(v);
    cout << "Minimum Element of this Array : " << findMin(v) << endl;
    return 0;
}
