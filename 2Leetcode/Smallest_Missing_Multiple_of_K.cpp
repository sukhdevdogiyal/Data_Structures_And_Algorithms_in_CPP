// Smallest Missing Multiple of K
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int missingMultiple(vector<int> &nums, int k)
{
    vector<int> mult;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % k == 0)
        {
            mult.push_back(nums[i]);
        }
    }
    if (mult.empty())
    {
        return k;
    }
    
    sort(mult.begin(), mult.end());
    int m=1;
    int cheak =mult[0];
    for (int j = 1; j < mult.size(); j++)
    {
        if (cheak==mult[j])
        {
            mult[j]=k-1;
        }
        else
        {
            cheak=mult[j];
        }
        
    }
    
    for (int i = 0; i < mult.size(); i++)
    {
        if (mult[i]==k-1)
        {
            continue;
        }
        
        if (mult[i] != k * (m))
        {
            return k * (m);
        }
        else
        {
            m++;
        }
        
    }
    return k * (m);
}
int main(int argc, char const *argv[])
{
    vector<int> i1 = {8, 2, 3, 4, 6};
    int k1 = 2;
    cout << "input 1 : " << missingMultiple(i1, k1) << endl;

    vector<int> i2 = {1, 4, 7, 10, 15};
    int k2 = 5;
    cout << "input 2 : " << missingMultiple(i2, k2) << endl;

    vector<int> i3 = {83,7, 96, 34, 56, 48, 30, 7, 14, 77, 66, 66, 66, 21, 17, 38, 7, 9};
    int k3 = 7;
    cout << "input 3 : " << missingMultiple(i3, k3) << endl;
    vector<int> i4 = {7,21};
    int k4 = 7;
    cout << "input 4 : " << missingMultiple(i4, k4) << endl;
    return 0;
}
