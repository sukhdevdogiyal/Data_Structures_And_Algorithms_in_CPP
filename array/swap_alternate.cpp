#include<iostream>
using namespace std;
void reverse(int arr[],int n)
 {
    int stat=0,end=1;
    while (end<n)
    {
        swap(arr[stat],arr[end]);
        stat=stat+2;
        end=end+2;
    }
    
    
 }
main()
 {
    int arr[4]={1,2,3,4};
    cout<<" array = ";
    for (int i = 0; i <4 ; i++)
    {
        cout<<arr[i]<<" ";
    }
    reverse(arr,4);
    cout<<"\nReverse array = ";
    for (int i = 0; i <4 ; i++)
    {
        cout<<arr[i]<<" ";
    }
    
 }