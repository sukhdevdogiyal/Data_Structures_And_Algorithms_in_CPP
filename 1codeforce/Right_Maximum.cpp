// Right Maximum
// https://codeforces.com/contest/2204/problem/B
#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int>input(n);
        for (int i = 0; i < n; i++)
        {
            cin>>input[i];
        }
        int ans = 0;
        int max = input[0];
        for (int i = 0; i < n; i++)
        {
            if (max<=input[i])
            {
                max = input[i];
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
