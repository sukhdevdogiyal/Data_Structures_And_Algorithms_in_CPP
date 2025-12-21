#include<iostream>
using namespace std;
bool found(int *arr,int n,int key)
{
    
    // Base case
    if (n<1)
    {
        return false;
    }
    int s=0;
    int e=n-1;
    int mid = s + (e-s)/2;
    if (arr[mid]==key)
    {
        return true;
    }
    else if(arr[mid]<key)
    {
        bool ans =found(arr+mid+1,n-mid+1,key);
        return ans;
    }
    else
    {
        bool ans =found(arr,n-mid-1,key);
        return ans;
    }
    
    
}
int main(int argc, char const *argv[])
{
    int arr[]={3,5,6,15,37,39,44};
    int n = sizeof(arr)/sizeof(int);
    int key =4444;
    if (found(arr,n,key))
    {
        cout<<"key is present in array";
    }
    else
    cout<<"key is not present in array";
    
    return 0;
}
