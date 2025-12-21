#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the decimal no ";
    cin>>n;
    int i=0,ans=0;
    while (n!=0)
    {
        int bit=n%2;
        ans=bit*pow(10,i)+ans;
        n=n/2;
        i++;
    }
    cout<<"BINARY= "<<ans;
    return 0    ;
}
