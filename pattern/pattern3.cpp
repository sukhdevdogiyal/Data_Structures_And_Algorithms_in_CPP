#include<iostream>
using namespace std;
int main()
{
    int i=1,n,j;
    cout<<"Enter the number";
    cin>>n;
    while (i<=n)
    {
        j=1;
        int c=n-i+1;
        while (j<=c)
        {
            cout<<"*";
            j++;
        }
        cout<<"\n";
        i++;
        
    }
    return 0;
    
}