#include<iostream>
using namespace std;
main()
{
    int n,count=1;
    cout<<"Enter the row ";
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++,count++)
        {
            cout<<count<<" ";
            
        }
        cout<<endl;
        
    }
    
}