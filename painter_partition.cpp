#include<iostream>
using namespace std;
bool isposible(int arr[],int n,int m,int mid)
 {
    int pentercount=1;
    int areasum=0;
    for (int i = 0; i < n; i++)
    {
        if (areasum+arr[i]<=mid)
        {
            areasum+=arr[i];
        }
        else
         {
            pentercount++;
            if (pentercount>m||arr[i]>mid)
            {
                return false;
            }
            areasum=arr[i];
         }
        
    }
    return true;
    
 }
main()
 {
    int arr[4]={5,5,5,5};
    int n=4;
    int m=2;
    int s=0;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    int e=sum;
    int mid=s+(e-s)/2;
    int ans=-1;
    while (s<=e)
    {
            
        if (isposible(arr,n,m,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
         {
            s=mid+1;
         }
        mid=s+(e-s)/2;
    }
     cout<<"ans = "<<ans;
    
 }