// sum of minimum and maximum element of all subarrays of size k

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int slove(vector<int> &arr, int k)
{
    deque<int> maxi;
    deque<int> mini;

    // process for first window
    for (int i = 0; i < k; i++)
    {
        int e = arr[i];
        // remove all small element
        while (!maxi.empty() && arr[maxi.back()] <= e)
            maxi.pop_back();
        // remove all big element
        while (!mini.empty() && arr[mini.back()] >= e)
            mini.pop_back();
        // push curr index
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = arr[maxi.front()] + arr[mini.front()];
    for (int i = k; i < arr.size(); i++)
    {
        // remove
        if (i - maxi.front() >= k)
            maxi.pop_front();
        if (i - mini.front() >= k)
            mini.pop_front();

        // add
        int e = arr[i];
        while (!maxi.empty() && arr[maxi.back()] <= e)
            maxi.pop_back();
        while (!mini.empty() && arr[mini.back()] >= e)
            mini.pop_back();
        maxi.push_back(i);
        mini.push_back(i);
        // store ans
        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << "all min and max sum each k size window : " << slove(arr, k) << endl;
    return 0;
}
