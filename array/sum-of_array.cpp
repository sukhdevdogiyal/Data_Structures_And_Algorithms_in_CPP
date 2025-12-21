#include<iostream>
using namespace std;
main()
{
    int arr[5],sum=0;
    cout<<"Enter the 5 no ";
    for (int  i = 0; i < 5; i++)
    {
        cin>>arr[i];
        sum=sum+arr[i];

    }
    cout<<"sum of array = "<<sum;

    
}