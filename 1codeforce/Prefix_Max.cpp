// Prefix Max
// https://codeforces.com/contest/2185/problem/B
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[maxi]<arr[i])
            {
                maxi = i;
            }
        }
        int max = arr[maxi];
        int sum = max*n;
        cout<<sum<<endl;
       
    }
    
    return 0;
}
/*
Input :-
4
5
2 1 4 5 3
2
5 1
3
3 2 1
2
6 7

output :-
25
10
9
14
*/