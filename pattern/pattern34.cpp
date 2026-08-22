#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n = 4;
    int k = 2;
    for (int i = 1; i <= n; i++)
    {
        k = k+i;
        for (int j = 1; j <= i; j++)
        {
            cout<<(k-j)<<" ";
        }
        cout<<endl;
    }
    k++;
    for (int i = 1; i <= n; i++)
    {
        k = k-i;
        for (int j = 1; j <= n-i+1; j++)
        {
            cout<<(k-j)<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
