/*
 Given an integer array arr[] of size n,
 find the inversion count in the array.
 Two array elements arr[i] and arr[j] form an inversion
 if arr[i] > arr[j] and i < j.
*/

#include<iostream>
using namespace std;

int merge(int *arr,int s,int e)
{
    int count = 0 ;
    // cout<<"befor :";
    // for (int i = s; i <= e; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    int mid = s + ( e - s ) / 2 ;
    int len1 = mid-s+1;
    int len2 = e-mid;
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    // copy 
    int mainindex = s;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[mainindex++];
    }
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[mainindex++];
    }
    

    // merge 
    int index1 = 0;
    int index2 = 0;
    mainindex = s;
    while (index1<len1&&index2<len2)
    {
        if (arr1[index1]<arr2[index2])
        {
            arr[mainindex++]=arr1[index1++];
        }
        else
        {
            count = count + len1-index1;
            arr[mainindex++]=arr2[index2++];
        }
        
    }
    while (index1<len1)
    {
        arr[mainindex++]=arr1[index1++];
    }
    while (index2<len2)
    {
        arr[mainindex++]=arr2[index2++];
    }
    //cout<<count<<endl;
    // cout<<"after :";
    // for (int i = s; i <= e; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }cout<<endl;

    delete[] arr1;
    delete[] arr2;
    return count;
 }
int mergesort(int *arr,int s,int e)
{int count=0;
    //cout<<"ev "<<count<<endl;   
    // Base case
    if (s>=e)
    {
        return 0;
    }
    int mid = s + (e-s)/2;
    count = count + mergesort(arr,s,mid);
    count = count + mergesort(arr,mid+1,e);
    count = count +  merge(arr,s,e);
    return count;
    
}
int main(int argc, char const *argv[])
{
    int arr[]={4,3,2,1};
    //int arr[]={38,27,43,3,9,82,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int count = mergesort(arr,0,n-1);
    cout<<"array after sort : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"inversion count of arrary : "<<count;

    return 0;
}
