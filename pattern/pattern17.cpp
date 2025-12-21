#include<iostream>
using namespace std;
main()
{
    int n;
    cout<<"Enter the row ";
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
         char ch='A'+j-1;
            cout<<ch;
        }
        cout<<endl;
        
    }
    
}