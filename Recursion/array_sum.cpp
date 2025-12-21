#include<iostream>
using namespace std;
int getsum(int *arr,int n)
{
    // Base case 
    if (n<1)
    {
        return 0;
    }
    int sp=getsum(arr+1,n-1);
    //cout<<sp<<endl;
    int BP = arr[0]+sp;
    //cout<<"BP1 = "<<arr[0]<<endl;
    //cout<<"BP = "<<BP<<endl;
    return BP;
    
}
int main(int argc, char const *argv[])
{
    //int arr[]={3,53,24,6,2,2,2};
    //int arr[]={0};
    int arr[]={9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"sum of array : "<<getsum(arr,n);
    return 0;
}
