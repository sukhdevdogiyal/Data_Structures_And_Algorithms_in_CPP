#include<iostream>
using namespace std;
void print(int arr[],int n)
 {
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
 }
main()
{
    int n=7;
    int arr[n];
    cout<<"Enter the array element ";
     for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Befor sort array = ";
   print(arr,n);
   for (int i = 0; i < n; i++)
   {
    int j=i-1;
    int temp=arr[i];
    while (j>=0)
    {
        if (arr[j]>temp)
        {
            arr[j+1]=arr[j];
        }
        else
         {
            break;
         }
         j--;
    }
    arr[j+1]=temp;
    
   }
   
    cout<<"\nAfter sort array = ";
   print(arr,n);
    
    
}