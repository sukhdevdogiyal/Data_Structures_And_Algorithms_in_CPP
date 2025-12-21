#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of tram : ";
    cin>>n;
    int a=0,b=1,sum=0;
    cout<<"FIBONACCI SERTIES "<<a<<" "<<b;
    for (int i = 1; i<=n-2; i++)
    {
        sum=a+b;
        cout<<" "<<sum;
        a=b;
        b=sum;
    }
    
    return 0;
}
