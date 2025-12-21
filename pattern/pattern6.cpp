#include<iostream>
using namespace std;
main()
{
    int n,count=1;
    cout<<"Enter the number";
    cin>> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<count;
            count++;
        }
        cout<<"\n";
        
    }
    

}