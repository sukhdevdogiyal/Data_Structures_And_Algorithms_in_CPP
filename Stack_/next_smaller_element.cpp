#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// T.C = O(n)
vector<int> nextsmaller(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

vector<int> prevsmaller(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

void print(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void findsmaller(vector<int> &arr, int n)
{
    cout << "arr = ";
    print(arr, n);

    vector<int> ans = nextsmaller(arr, n);
    cout << "next smaller = ";
    print(ans, ans.size());

    ans = prevsmaller(arr, n);
    cout << "prev smaller = ";
    print(ans, ans.size());
    cout << endl;
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 1, 4, 3};
    findsmaller(arr, arr.size());

    arr = {5, 4, 3, 2};
    findsmaller(arr, arr.size());

    arr = {5, 5, 5, 5};
    findsmaller(arr, arr.size());

    arr = {5, 6, 7, 8, 9};
    findsmaller(arr, arr.size());

    return 0;
}
