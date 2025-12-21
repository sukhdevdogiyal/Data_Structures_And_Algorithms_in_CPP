#include <iostream>
using namespace std;
bool issortedarray(int *arr, int n)
{
    // Base case
    if (n == 0 || n == 1)
    {
        return true;
    }
    // processing
    if (arr[0] > arr[1])
    {
        return false;
    }
    // recrisive relation
    else
    {
        bool ans = issortedarray(arr + 1, n - 1);
        return ans;
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {2, 4, 6, 8, 11, 55, 13};
    if (issortedarray(arr, sizeof(arr)))
    {
        cout << "Array is sorted order";
    }
    else
        cout << "Array is NOT sorted order";
    return 0;
}
