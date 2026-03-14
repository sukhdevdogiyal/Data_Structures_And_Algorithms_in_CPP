// 3862. Find the Smallest Balanced Index
// https://leetcode.com/contest/weekly-contest-492/problems/find-the-smallest-balanced-index/description/
#include <iostream>
#include <vector>
using namespace std;
int smallestBalancedIndex1(vector<int> &nums)
{
    int ans = -1;
    int s = -1, e = nums.size();
    int sum = 0, prod = 1;
    while (s < e)
    {
        if (sum == prod && s + 1 == e - 1)
        {
            ans = s + 1;
            break;
        }
        else if (sum < prod)
        {
            s++;
            sum += nums[s];
        }
        else if (sum > prod)
        {
            e--;
            prod *= nums[e];
        }
        else
        {
            break;
        }
    }
    return ans;
}
int smallestBalancedIndex(vector<int> &nums)
{
    int n = nums.size();
    int ans = -1;
    int totalsum = 0;
    for(int i:nums)
    totalsum+=i;
    int i = n-1;
    int sum = totalsum;
    int prod = 1;
    while (i>0)
    {
        //cout<<prod<<endl;
        if(sum==prod&&i-1>=0)
        {
          ans = i;  
        }
        else if(sum<prod)break;
        else 
        {
            sum-=nums[i];
            i--;
            prod*=nums[i];
        }
    }
    return ans;
    
}
int main(int argc, char const *argv[])
{
    vector<int> v = {2, 1, 2};
    cout << "Smallest Balanced Index = " << smallestBalancedIndex(v) << endl;
    v = {2, 8, 2, 2, 5};
    cout << "Smallest Balanced Index = " << smallestBalancedIndex(v) << endl;
    v = {1};
    cout << "Smallest Balanced Index = " << smallestBalancedIndex(v) << endl;
    v = {5, 4, 1, 2, 10};
    cout << "Smallest Balanced Index = " << smallestBalancedIndex(v) << endl;

    return 0;
}
