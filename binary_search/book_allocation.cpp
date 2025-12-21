#include<iostream>
using namespace std;
bool isposible(int arr[],int n,int m,int mid)
 {
    int studentcount=1;
    int pagesum=0;
    for (int i = 0; i < n; i++)
    {
        if ((pagesum+arr[i])<=mid)
        {
            pagesum+=arr[i];
        }
        else
        {
            studentcount++;
            if (studentcount>m||arr[i]>mid)
            {
                return 0;
            }
            pagesum=arr[i];
        }
        
    }
    return 1;
    
 }
main()
 {
    int arr[5]={10,20,30,40,50};
    int key=3;
    int s=0,sum=0;
    for (int i = 0; i < 5; i++)
    {
        sum+=arr[i];
    }
    int e=sum;
    int mid=s+(e-s)/2;
    int ans=-1;
    while (s<=e)
    {
        if (isposible(arr,5,key,mid)==1)
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
