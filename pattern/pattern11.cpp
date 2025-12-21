#include<iostream>
using namespace std;
main()
{
    int n;
    cout<<"Enter the row ";
    cin>>n;
    for (int i = 1; i <= n; i++)
    {int c=i;
        for (int j = 1; j <= i; j++)
        {
            cout<<c;
            c--;
        }
        cout<<endl;
        
    }
    
}