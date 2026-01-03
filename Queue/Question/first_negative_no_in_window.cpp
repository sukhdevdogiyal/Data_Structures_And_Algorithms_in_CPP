// first negative integer in every window of size k

#include <iostream>
#include <queue>
using namespace std;

vector<int> firstneg(vector<int> &arr, int k)
{
    if (k > arr.size())
        return arr;

    queue<int> q;
    // process first window
    for (int i = 0; i < k; i++)
        if (arr[i] < 0)
            q.push(i);

    // store first ans
    vector<int> ans;
    if (q.empty())
        ans.push_back(0);
    else
        ans.push_back(arr[q.front()]);

    // process other window
    for (int i = k; i < arr.size(); i++)
    {
        // remove outside window element
        if (!q.empty() && i - q.front() >= k)
            q.pop();

        // add element
        if (arr[i] < 0)
            q.push(i);

        // store ans
        if (q.empty())
            ans.push_back(0);
        else
            ans.push_back(arr[q.front()]);
    }
    return ans;
}
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {-8, 9, 3, -6, 10};
    int k = 2;
    cout << "input 1 : ";
    print(arr);
    cout << "window size : " << k << endl;
    vector<int> ans = firstneg(arr, k);
    cout << "first neg : ";
    print(ans);

    cout << endl;
    arr = {3, -6, -4, 3, 8, 8, -2, 1, 0, -9};
    k = 3;
    cout << "input 2 : ";
    print(arr);
    cout << "window size : " << k << endl;
    ans = firstneg(arr, k);
    cout << "first neg : ";
    print(ans);

    return 0;
}
