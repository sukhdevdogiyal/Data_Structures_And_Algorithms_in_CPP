// 442. Find All Duplicates in an Array

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> findDuplicates(vector<int> &nums)
{
    sort(nums.begin(),nums.end());
    vector<int>v;
    int i=1;
    while (i<nums.size())
    {
        if (nums[i]==nums[i-1])
        {
            v.push_back(nums[i]);
        }
        i++;
    }
    return v;
    
}
void print(vector<int> arr)
{
    cout<<"\nDuplicates in an Array : ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
}
main()
{
    vector<int> arr = {4,3,2,7,8,2,3,1};
    vector<int>ans=findDuplicates(arr);
    print(ans);
    arr = {1,1,2};
    ans=findDuplicates(arr);
    print(ans);
    arr = {1};
    ans=findDuplicates(arr);
    print(ans);
    
}