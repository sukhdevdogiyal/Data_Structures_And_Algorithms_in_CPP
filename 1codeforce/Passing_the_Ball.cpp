// Passing the Ball
// https://codeforces.com/contest/2204/problem/A

// Approch 
/*
* find first L
*/
#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
        int t; 
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            vector<char>input(n);
            for (int i = 0; i < n; i++)
            {
                cin>>input[i];
            }
            int ans =0;
            for (int i = 0; i < n; i++)
            {
                ans++;
                if (input[i]=='L')
                break;
            }
            cout<<ans<<endl;
        }
        return 0;
    
    return 0;
}