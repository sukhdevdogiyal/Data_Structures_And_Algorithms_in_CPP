#include<iostream>
using namespace std;
main()
{
    int arr[6]={1,0,1,0,1,0};
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    int i=0,j=5;
    while (i<j)
    {
        if (arr[i]==0)
        {
            i++;
        }
        if(arr[j]==1)
        {
            j--;
        }
        else 
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        
        
    }
    cout<<endl;
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    
}