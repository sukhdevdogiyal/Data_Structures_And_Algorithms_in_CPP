// K-th Largest Sum Contiguous Subarray
// GFG
// https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

// Approach #1
// T.C = O(n^2log(n))
// S.C = O(n^2)
int kthLargest1(vector<int> &arr, int k)
{
    // store k largest sum
    vector<int> subarray;
    int n = arr.size();
    // process all subarray
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            // only top k sum store in pq
            subarray.push_back(sum);
        }
    }
    sort(subarray.begin(), subarray.end());
    return subarray[subarray.size() - k];
}

// Approach #2
// using heap
// T.C = O(n^2log(k))
// S.C = O(k)
int kthLargest(vector<int> &arr, int k)
{
    // store k largest sum
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();
    // process all subarray
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            // only top k sum store in pq
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 6, 4, 1};
    int k = 3;
    cout << k << " Latgest Sum of subarray1 : " << kthLargest1(arr, k) << endl;
    cout << k << " Latgest Sum of subarray : " << kthLargest(arr, k) << endl
         << endl;

    arr = {3, 2, 1};
    k = 2;
    cout << k << " Latgest Sum of subarray1 : " << kthLargest1(arr, k) << endl;
    cout << k << " Latgest Sum of subarray : " << kthLargest(arr, k) << endl
         << endl;
    return 0;
}
