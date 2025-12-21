#include<iostream>
using namespace std;
main()
{
    int n;
    cout<<"Enter the row ";
    cin>>n;
        char ch='A';
    for (int i = 1; i <= n; i++)
    { 
        for (int j = 1; j <= i; j++)
        {
            cout<<ch++;
        }
        cout<<endl;
        
    }
    
}