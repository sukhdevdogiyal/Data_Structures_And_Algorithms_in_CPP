#include<iostream>
using namespace std;
main()
{
    int n;
    cout<<"Enter the Row";
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=i-1;j++)
        {
            cout<<" ";
        }
        for (int j = 1; j <=i*2-1; j++)
        {
            cout<<"*";
        }
        
        for (int j = 1; j>=2*n-3*j+5; j++)
        {
            cout<<" ";
        }
        
        
       for (int j = n*2-2*i+2; j >=1; j--)
        {
            cout<<" ";
        }
        for (int j = 1; j <=i*2-1; j++)
        {
            cout<<"*";
        }
        cout<<"\n";
        
    }
    
}