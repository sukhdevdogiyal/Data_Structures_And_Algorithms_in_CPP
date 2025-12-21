#include<iostream>
#include<array>
using namespace std;
int main(int argc, char const *argv[])
{
    array<int,6>arr;
    cout<<"Enter the array element";
    for (int  i = 0; i < 6; i++)
    {
        cin>>arr[i];
    }
    cout<<"array : ";
    for(int j:arr)
    {
        cout<<j<<" ";
    }
    cout<<endl<<arr.size();
    cout<<endl<<arr.at(5);
    cout<<endl<<arr.empty();
    cout<<endl<<arr.front();
    cout<<endl<<arr.back();
    cout<<"\naddress arr[0]="<<&arr[0];
    cout<<"\naddress arr[1]="<<&arr[1];
    return 0;
}
