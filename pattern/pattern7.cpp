#include<iostream>
using namespace std;
main()
{
    int n;
    cout <<"Entre the Row ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < i; j++)
       {
        cout<<"*";
       }
       cout<<"\n";
       
    }
    
}