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
            int c=i;
        for (int j = 1; j < n-i+1; j++)
        {
            cout<<c++;
        }
        
        cout<<endl;
        
    }
    
}