#include<iostream>
using namespace std;
int main()
{
    int n,i=1;
    cout<<"Enter the Row";
    cin>>n;
    while (i<=n)
    {
        int j=1;
        while (j<=n)
        {
            cout<<(n-j+1);
            j++;
        }
        cout<<"\n";
        i++;
        

    }
    
}