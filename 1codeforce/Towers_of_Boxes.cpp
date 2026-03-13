// Towers of Boxes
//https://codeforces.com/contest/2203/problem/A
// n identical boxes. The weight of each box is m, and the durability of each box is d.
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,m,d;
        cin>>n>>m>>d;
        int len = d/m;
        len++;
        int tobox = n/len;
        if(n%len)
        tobox++;
        cout<<tobox<<endl;
    }
    
    return 0;
}
