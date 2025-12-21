#include<iostream>
using namespace std;
int find(int arr[],int n,int key)
   {
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==key)
        {
            return 1;
        }
        
    }
    return 0;
    
   }
main()
 {
    int arr[]={99,55,4,6,5,7,76,34,9,0,8};
    int key;
    cout<<"Enter the key ";
    cin>>key;
    if (find(arr,11,key)==1)
    {
        cout<<"\nkey is find ";

    }
    else
    {
        cout<<"\nkey is not find";
    }
    
    
 }