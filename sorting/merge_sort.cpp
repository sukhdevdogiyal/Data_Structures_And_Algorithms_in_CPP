#include <iostream>
using namespace std;
void merge1(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    while (i < j && j <= e)
    {
        if (arr[i] < arr[j])
        {
            i++;
        }
        else
        {
            int temp = arr[j];
            int k = j;
            for (; k > i; k--)
            {
                arr[k] = arr[k - 1];
            }
            arr[k] = temp;
            // swap(arr[i],arr[j]);
            i++;
            j++;
        }
    }
}


void merge(int *arr, int s, int e)
{
    // cout<<s<<" "<<e<<endl;
    cout << "merge: ";
    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int mid = (s + e) / 2;
    int l1 = mid - s + 1;
    int l2 = e - mid;
    int *arr1 = new int[l1];
    int *arr2 = new int[l2];
    int z = s;
    for (int i = 0; i < l1; i++)
    {
        arr1[i] = arr[z++];
        // cout << arr1[i]<<" ";
    }

    for (int i = 0; i < l2; i++)
    {
        arr2[i] = arr[z++];
        // cout << arr2[i]<<" ";
    }
    int i = 0, j = 0, k = s;
    while (i < l1 && j < l2)
    {
        if (arr1[i] > arr2[j])
        {
            arr[k++] = arr2[j++];
        }
        else
        {
            arr[k++] = arr1[i++];
        }
    }
    while (j < l2)
    {
        arr[k++] = arr2[j++];
    }
    while (i < l1)
    {
        arr[k++] = arr1[i++];
    }

    delete[] arr1;
    delete[] arr2;
    cout << "sort : ";
    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void mergesort(int *arr, int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Base case
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge1(arr, s, e);
}
int main(int argc, char const *argv[])
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Befor sort : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergesort(arr, 0, n - 1);
    // int arr1[]={90,27};//,38,43,9,10,82};
    // int n1=2;
    // merge1(arr1,0,n1-1);
    cout << "After sort : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
