#include<iostream>
using namespace std;
main()
{
    int n;
    cout<<"Enter the row ";
    cin>>n;
    for (int i = 1; i <= n; i++)
    { 
        for (int space = 1; space <= i-1; space++)
        {
            cout<<" ";
        }
        for (int j = 0; j < n-i+1; j++)
        {
            cout<<"*";
        }
        
        cout<<endl;
        
    }
    
}