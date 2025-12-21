#include <iostream>
using namespace std;
int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    cout << "Pivot = " << pivot << endl;

    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        // cout<<arr[i]<<endl;
        if (arr[i] < pivot)
        {
            count++;
        }
    }
    // cout<<count<<endl;
    swap(arr[s], arr[s + count]);
    int i = s;
    int j = e;
    while (i < j)
    {
        if (arr[i] < pivot)
        {
            i++;
        }
        else if (arr[j] > pivot)
        {
            j--;
        }
        else
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    cout<<"Pivot position : ";
    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // cout<<s+count<<endl;
    return s + count;
}
void quicksort(int *arr, int s, int e)
{
    // Base case
    if (s >= e)
    {
        return;
    }

    // Partition
    int p = partition(arr, s, e);

    quicksort(arr, s, p - 1);
    quicksort(arr, p + 1, e);
}
int main(int argc, char const *argv[])
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    // int arr[] = {6 ,6 ,-6, -2, -4, -6, 2, -6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Befor sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, n - 1);
    cout << "After sorting : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
