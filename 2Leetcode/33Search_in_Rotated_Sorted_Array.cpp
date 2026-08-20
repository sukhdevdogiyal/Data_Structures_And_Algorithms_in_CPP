// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>v,int s,int e)
{
    int n=e;
    int mid=-1,ans=-1;
    while (s<=e)
    {
        mid=s+(e-s)/2;
        if(v[mid]>v[n])
        {
            s=mid+1;
        }
        else
        {
            ans=mid;
            e=mid-1;
        }
    }
    return ans;
    
}

int binary(vector<int> v, int s, int e,int t)
{
    int mid = -1;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (v[mid] ==t)
        {
            //ans=mid;
            //break;
            return mid;
        }
        else if(v[mid]>t)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int second=search(nums,0,nums.size()-1);
    int ans=-1;
    if(target>=nums[0]&&second>0)
    {
        ans=binary(nums,0,second-1,target);
    }
    else
    {
        ans=binary(nums,second,nums.size()-1,target);
    }
    return ans;
}

int main()
{
    // Test Case 1
    vector<int> nums1 = {4,5,6,7,0,1,2};
    int target1 = 0;
    cout << "Test Case 1: " << search(nums1,target1) << endl;

    // Test Case 2
    vector<int> nums2 = {4,5,6,7,0,1,2};
    int target2 = 3;
    cout << "Test Case 2: " << search(nums2,target2) << endl;

    // Test Case 3
    vector<int> nums3 = {1};
    int target3 = 1;
    cout << "Test Case 3: " << search(nums3,target3) << endl;

    return 0;
}
