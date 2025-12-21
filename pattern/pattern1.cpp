#include<iostream>
using namespace std;
int main()
{
    int i=1,j,n;
    cout<<"Enter the Row";
    cin>>n;
    while(i<=n)
      {j=1;
        while(j<=n)
          {
            cout<<"*";
            j++;
          }
        cout<<"\n";
        i++;
      }
    return 0;
    
}