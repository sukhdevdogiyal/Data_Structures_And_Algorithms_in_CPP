#include<iostream>
using namespace std;
int main()
{
    int n,i=1,sum=0,sum1=0;
    cout<<"Enter the number : ";
    cin>>n;
    while (i<=n)
    {
        if(i%2==0)
        {
           sum=sum+i;
        }
        else
        {
            sum1=sum1+i;
        }
        i++;
    }
    cout<<"sum of odd num = "<<sum1<<endl;
    cout<<"sum of even num = "<<sum;
    return 0;
    
}