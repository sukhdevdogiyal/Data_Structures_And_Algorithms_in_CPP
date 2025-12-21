#include <iostream>
#include <set>
#include <vector>
using namespace std;
int longestBalanced(vector<int> &nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        s.insert(nums[i]);
    }
    int be = 0, bo = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0)
            be++;
        else
            bo++;
    }
    int e = 0, o = 0;
    for (int i : s)
    {
        if (i % 2 == 0)
            e++;
        else
            o++;
    }
    if(e==0||o==0) return 0;
    int f = 0;
    if (e < o)
    {
        f = e;
        return f + bo;
    }
    else
    {
        f = o;
        return f + be;
    }
}

int main(int argc, char const *argv[])
{
    set<int> s;
    vector<int> nums = {14,10,9};
cout<<longestBalanced(nums);
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     s.insert(nums[i]);
    // }
    // for (int i : s)
    // {
    //     cout << i << " ";
    // }

    return 0;
}
