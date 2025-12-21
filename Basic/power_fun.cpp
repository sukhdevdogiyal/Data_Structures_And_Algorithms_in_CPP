#include<iostream>
using namespace std;
int power()
{
    int a,b;
    cout<<"Enter the a and b"<<endl;
    cin>>a>>b;
    int ans=1;
    for (int i = 1; i <=b; i++)
    {
        ans=ans*a;
    }
    return ans;
    
}
main()
{   //calculate the pow(a,b)
    int ans=power();
    cout<<"a to the power b = "<<ans<<endl;
    int ans2=power();
    cout<<"a to the power b = "<<ans2<<endl;
    int ans3=power();
    cout<<"a to the power b = "<<ans3<<endl;
}