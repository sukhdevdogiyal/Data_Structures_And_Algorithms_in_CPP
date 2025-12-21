#include<iostream>
using namespace std;
bool found(int *arr,int n,int key)
{
    // Base case 
    if (n<1)
    {
        return false;
    }
    if (arr[0]==key)
    {
        return true;
    }
    else
    {
        bool ans = found(arr+1,n-1,key);
        return ans;
    }
    
    
}
int main(int argc, char const *argv[])
{
    //int arr[]={3,53,24,6,2,2,2};
    //int arr[]={0};
    int arr[]={9};
    int key = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    if (found(arr,n,key))
    {
        cout<<"Key is present in array";
    }
    else
    {
        cout<<"Key is not present in array";
    }
    
    return 0;
}
