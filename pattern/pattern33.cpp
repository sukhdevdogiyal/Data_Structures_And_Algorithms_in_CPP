#include<iostream>
using namespace std;
main()
 {
    int n=10;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n-i; j++)
        {
            cout<<"\t ";
        }
        for (int k = 1; k <=i*2; k++)
        {
            cout<<"\t*";
        }
        
        cout<<"\n"<<endl;
    }
    for (int i = n; i >=1; i--)
    {
        for (int j = 1; j <=n-i; j++)
        {
            cout<<"\t ";
        }
        for (int k = 1; k <=i*2; k++)
        {
            cout<<"\t*";
        }
        
        cout<<"\n"<<endl;
    }
    
 }