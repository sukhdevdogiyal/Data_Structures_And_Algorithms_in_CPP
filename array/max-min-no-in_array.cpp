#include<iostream>
using namespace std;
int max(int arr[],int size)
  {
    int max=INT32_MIN;
    for (int i = 0; i<size; i++)
    {
        if (max<arr[i])
        {
            max=arr[i];
        }
    }
     return max;
  }
int min(int arr[],int size)
  {
    int min=INT32_MAX;
    for (int i = 0; i<size; i++)
    {
        if (min>arr[i])
        {
            min=arr[i];
        }
    }
        return min;
  }
main()
{
    int size;
    cout<<"Enter the size of array ";
    cin>>size;
    int arr[size];
    cout<<"\nEnter the "<<size<<" element";
    for (int i = 0; i <size; i++)
    {
        cin>>arr[i];

    }
    cout<<"\nmaximum value = "<<max(arr,size);
    cout<<"\nminimum value = "<<min(arr,size);
    
}