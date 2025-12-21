// 34. Find First and Last Position of Element in Sorted Array


#include <iostream>
#include <algorithm>
using namespace std;
int firstoccurrence(int arr[], int n, int key)
{
    cout<<"Key = " << key;
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;
    int ans=-1;
    while (start <= end)
    {
        if (key == arr[mid] && start <= end)
        {
            ans=mid;
            end=mid-1;
        }
        if (key > arr[mid] && start <= end)
        {
            start = mid + 1;
        }
        else // key<mid
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return ans;
}
int lastoccurrence(int arr[], int n, int key)
{
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;
    int ans=-1;
    while (start <= end)
    {
        if (key == arr[mid] && start <= end)
        {
            ans=mid;
            start=mid+1;
        }
        else if (key > arr[mid] && start <= end)
        {
            start = mid + 1;
        }
        else // key<mid
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return ans;

}
main()
{
    int even[7] = {1,2,3,3,3,3,5};
    sort(even, even + 7);
    for (int i = 0; i < 7; i++)
    {
        cout << even[i] << " ";
    }
    int key1;

    cout << "\nenter the key = ";
    cin >> key1;

    int index1 = firstoccurrence(even, 7, key1);
    cout << "\noccurrence fast index of key = " << index1;


    int index2 = lastoccurrence(even, 7, key1);
    cout << "\noccurrence last index of key = " << index2<<endl;
    
    cout<<endl;
    int arr[]={5,7,7,8,8,10};
    cout<<"arr = 5,7,7,8,8,10 "<<endl;
    int key = 7;
    index1 = firstoccurrence(arr, 6, key);
    cout << "\noccurrence fast index of key = " << index1;

    index2 = lastoccurrence(arr, 6, key);
    cout << "\noccurrence last index of key = " << index2;
}