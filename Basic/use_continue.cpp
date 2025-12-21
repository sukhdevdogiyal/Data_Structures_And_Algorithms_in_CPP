#include<iostream>
using namespace std;
main()
{
    int n;
    cout<<"Enter the no";
    cin>>n;
    for (int i = 1; i<=n; i++)
    {
        cout<<i<<" ";
        continue;
        cout<<"hii";
    }
    cout<<"\n"<<"EVEN no ";
    for (int i = 1; i <=n; i++)
    {

        if (i%2==0)
        {
            continue;
        }
        cout<<i<<" ";
        
    }
    
    
}