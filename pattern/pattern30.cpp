#include<iostream>
using namespace std;
main()
{
    int n;
    cout<<"Enter the row ";
    cin>>n;
    for (int i = 1; i <= n; i++)
    { 
        for (int space = 1; space <= n-i+1; space++)
        {
            cout<<space;
        }
        for (int j = 1; j <= i*2-2; j++)
        {
            cout<<"*";
        }
        for (int k = n-i+1; k >=1; k--)
        {
            cout<<k;
        }
        
        
        cout<<endl;
        
    }
    
}