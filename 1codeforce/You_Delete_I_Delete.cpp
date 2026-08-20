// You Delete, I Delete
// https://codeforces.com/contest/2248/problem/A
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        s.erase(s.begin()+s.find('0'));
        s.erase(s.begin()+s.find('1'));
        cout<<s<<endl;
    }
    
    return 0;
}
