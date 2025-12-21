#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    //int arr1[n];
    int *arr = new int[n];
    //cout<<n*sizeof(*arr);
    cout<<"Address of static memory &arr = "<<&arr;
    cout<<"\nAddress of Dynmic memory all Elemant of array : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr+i<<" "; //*(i+arr);
    }
    cout<<"\nEnter the "<<n<<" elemant of array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i]; //*(arr+i);
    }
    cout<<"Elemant of array : ";
    for (int i = 0; i < n; i++)
    {
        cout<<i[arr]<<" "; //*(i+arr);
    }
    
    delete []arr;
    return 0;
}
