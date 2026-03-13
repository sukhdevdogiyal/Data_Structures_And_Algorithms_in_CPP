// 169. Majority Element
// https://leetcode.com/problems/majority-element/description/
// The majority element is the element that appears more than ⌊n / 2⌋ times.
#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

// Approch #1
// T.C = O(nlog(n))
// S.C = O(1)
// using sort function
int majorityElement1(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(),nums.end());
    return nums[n/2];
}

// Approch #2
// T.C = O(n)
// S.C = O(n)
// using onordered map
int majorityElement2(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> count;
    for (int i : nums)
    {
        count[i]++;
    }
    int c = n / 2;
    for (auto i : count)
    {
        if (i.second > c)
            return i.first;
    }
}

// Approch #3
// T.C = O(n)
// S.C = O(1)
// Moore Voting Algorithm
int majorityElement3(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    int candidate = 0;
    for (int i : nums)
    {
        if (count == 0)
            candidate = i;
        if (candidate == i)
            count++;
        else
            count--;
    }
    return candidate;
}

// print input
void print(vector<int> &arr)
{
    cout << "Input : ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    vector<int> input = {3, 2, 3};
    print(input);
    cout<<"Approch 1 Majority Element : " << majorityElement1(input) << endl;
    cout<<"Approch 2 Majority Element : " << majorityElement2(input) << endl;
    cout<<"Approch 3 Majority Element : " << majorityElement3(input) << endl;
    
    cout<<endl;
    input= {2,2,1,1,1,2,2};
    print(input);
    cout<<"Approch 1 Majority Element : " << majorityElement1(input) << endl;
    cout<<"Approch 2 Majority Element : " << majorityElement2(input) << endl;
    cout<<"Approch 3 Majority Element : " << majorityElement3(input) << endl;
    return 0;
}
