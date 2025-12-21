#include <iostream>
#include <vector>
using namespace std;
int sumDivisibleByK(vector<int> &nums, int k)
{
    vector<int> fre(101,0);
    for (int i = 0; i < nums.size(); i++)
    {
        int a = nums[i];
        fre[a]++;
    }
    int sum = 0;
    for (int i = 1; i <= 100 ; i++)
    {
        if (fre[i] % k == 0)
        {
            sum = sum + fre[i]*i;
        }
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    //vector<int> nums = {1,2,2,3,3,3,3,4};
    //vector<int> nums = {1,2,3,4,5};
   // vector<int> nums = {4,4,4,1,2,3};
    vector<int> nums = {1};
    int k = 1;
    cout << sumDivisibleByK(nums,k);
     return 0;
}
