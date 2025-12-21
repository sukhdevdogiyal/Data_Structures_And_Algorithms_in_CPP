// 1672. Richest Customer Wealth
#include <iostream>
#include <vector>
using namespace std;
int maximumWealth(vector<vector<int>> &accounts)
{
    int maxwealth = 0;
    for (int i = 0; i < accounts.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < accounts[i].size(); j++)
        {
            sum += accounts[i][j];
        }
        if (sum > maxwealth)
        {
            maxwealth = sum;
        }
    }
    return maxwealth;
}
int main(int argc, char const *argv[])
{
vector<vector<int>> v={{1,2,3},{3,2,1}};
//vector<vector<int>> v={{2,8,7},{7,1,3},{1,9,5}};
cout<<"customer is the richest with a wealth of "<<maximumWealth(v);
    return 0;
}
