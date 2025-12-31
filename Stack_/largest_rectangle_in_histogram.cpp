#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> nextsmaller(vector<int> &hight, int n)
{
    // store smaller element index
    stack<int> s;
    s.push(n);

    // find smaller element
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = hight[i];
        while (s.top() != n && hight[s.top()] >= curr)
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevsmaller(vector<int> &hight, int n)
{
    // store smaller element index
    stack<int> s;
    s.push(-1);

    // find smaller element
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = hight[i];
        while (s.top() != -1 && hight[s.top()] >= curr)
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestractangle(vector<int> &hight)
{
    int n = hight.size();
    // find and store next and prev smaller element index
    vector<int> next = nextsmaller(hight, n);
    vector<int> prev = prevsmaller(hight, n);
    // find max area
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        int l = hight[i];
        int b = next[i] - prev[i] - 1;
        int newarea = l * b;
        area = max(newarea, area);
    }
    return area;
}
void print(vector<int> &arr, int n)
{
    cout << "Hight : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    vector<int> hight = {2, 1, 5, 6, 2, 3};
    print(hight, hight.size());
    cout << "Largest Ractangle area : " << largestractangle(hight) << endl;

    cout << endl;
    hight = {5, 5, 5, 5, 5, 5};
    print(hight, hight.size());
    cout << "Largest Ractangle area : " << largestractangle(hight) << endl;

    cout << endl;
    hight = {1, 2, 3, 4, 5};
    print(hight, hight.size());
    cout << "Largest Ractangle area : " << largestractangle(hight) << endl;
    return 0;
}
