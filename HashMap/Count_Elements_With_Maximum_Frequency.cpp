// 3005. Count Elements With Maximum Frequency
// leetcode
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int maxFrequencyElements(vector<int> &nums)
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }
    int max = 0;
    int ans = 0;
    for (auto i : m)
    {
        if (i.second > max)
        {
            max = i.second;
            ans = max;
        }
        else if (i.second == max)
        {
            ans += max;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,2,3,1,4};
    cout<<"Count element with max frequency : "<<maxFrequencyElements(nums)<<endl;
    cout<<endl;
    
    nums = {1,2,3,4,5};
    cout<<"Count element with max frequency : "<<maxFrequencyElements(nums)<<endl;
    return 0;
}
