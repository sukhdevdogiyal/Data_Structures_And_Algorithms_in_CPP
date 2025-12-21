#include<iostream>
using namespace std;
main()
{
    int n;
    cout<<"Enter the row ";
    cin>>n;
    for (int i = n; i >= 1; i--)
    { 
        char ch='A'+i-1;
        for (int j = 0; j <= n-i; j++)
        {
            cout<<ch++;
        }
        cout<<endl;
        
    }
    
}