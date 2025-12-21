#include<iostream>
#include<algorithm>
#include<array>
using namespace std;
int ispossible(int arr[],int n,int m,int mid)
 {
    int cowcount=1;
    int lastpos=arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i]-lastpos>=mid)
        {
            cowcount++;
            if (cowcount==m)
            {
                return true;
            }
            lastpos=arr[i];
        }
        
    }
    return false;
    
 }
main()
 {
   int n=5;
    int arr[n]={4,2,1,3,6};
    int s=0,maxi=-1,m=2;
    for (int  i = 0; i < n; i++)
    {
        maxi=max(maxi,arr[i]);
    }
    sort(arr,arr+n);
    int e=maxi;
    int mid=s+(e-s)/2;
    int ans=-1;
    while (s<=e)
    {
        if (ispossible(arr,n,m,mid))
        {
            ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
         mid=s+(e-s)/2;
    }
    cout<<"ans = "<<ans;
    
 }