#include <iostream>
#include <algorithm>
using namespace std;
int binarysearch(int arr[], int n, int key)
{
    cout<<"Key = " << key;
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        if (key == arr[mid] && start <= end)
        {
            return mid;
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
    return -1;
}
main()
{
    int even[10] = {22, 6, 7, 3, 0, 14, 35, 75, 100, 10};
    int odd[5] = {7, 2, 88, 46, 13};
    sort(even, even + 10);
    sort(odd, odd + 5);
    cout<<"even array : ";
    for (int i = 0; i < 10; i++)
    {
        cout << even[i] << " ";
    }
    int key1;

    cout << "\nenter the key = ";
    cin >> key1;

    int index1 = binarysearch(even, 10, key1);

    cout << "\nindex of key = " << index1<< endl;

    cout<<"\nodd array : ";
    for (int i = 0; i < 5; i++)
    {
        cout << odd[i] << " ";
    }
    int key2;
    cout << "\nenter the key = ";
    cin >> key2;
    int index2 = binarysearch(odd, 5, key2);
    cout << "\nindex of key = " << index2;
}