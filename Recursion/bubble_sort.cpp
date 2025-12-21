#include<iostream>
using namespace std;
void bubblesort(int *arr,int n)
{
   // cout<<n<<endl;
    // Base Case
    if(n==1)
    {
        return ;
    }
    
    if (arr[0]>arr[1])
    {
        swap(arr[0],arr[1]);
    }
    bubblesort(arr+1,n-1);
    bubblesort(arr,n-1);
    
}
int main(int argc, char const *argv[])
{
    int arr[]={33,3,645,0,-22,35,54,-433,2344};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
