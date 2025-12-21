#include<iostream>
using namespace std;
main()
{
    int n;
    cout<<"Enter the row ";
    cin>>n;
    for (int i = 1; i <= n; i++)
    { 
        for (int space = 1; space <= n-i; space++)
        {
            cout<<" ";
        }
        for (int j = i; j >0; j--)
        {
            int c=j;
            cout<<c++;
        }
        
        cout<<endl;
        
    }
    
}