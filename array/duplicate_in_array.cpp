#include<iostream>
using namespace std;
int duplicate(int arr[],int n)
 {
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        ans=ans^arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        ans=ans^i;
    }
    
    return ans;
    
 }
main()
{
    int arr[5]={1,2,3,4,3};//  All element in range 1 to size-1 of array 
    int ans=duplicate(arr,5);
    cout<<"Duplicate element of array = "<<ans;
}