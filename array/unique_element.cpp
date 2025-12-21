#include<iostream>
using namespace std;
int unique(int arr[],int n)
 {
    int ans=0;
    for (int i = 0; i <n; i++)
    {
        ans=ans^arr[i];
    }
    return ans;
 }
main()
{
    int arr[]={2,3,1,1,2};
    int ans=unique(arr,5);
    cout<<"Unique element of array = "<<ans;
}