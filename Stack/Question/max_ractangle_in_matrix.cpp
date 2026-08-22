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

// T.C. = O(nxm)
// S.C. = O(m)
int maxarea(vector<vector<int>> &m)
{
    int n = m.size();
    int area = largestractangle(m[0]);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            if (m[i][j] != 0)
                m[i][j] += m[i - 1][j];
        }
        int newarea = largestractangle(m[i]);
        area = max(area, newarea);
    }

    return area;
}
void print(vector<vector<int>> &m)
{
    cout << "matrix :-" << endl;
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> m = {{0, 1, 1, 0},
                             {1, 1, 1, 1},
                             {1, 1, 1, 1},
                             {1, 1, 0, 0}};

    cout << "max rectangle area : " << maxarea(m) << endl;
    print(m);

    cout << endl;
    m = {{1, 1},
         {1, 1}};
    cout << "max rectangle area : " << maxarea(m) << endl;

    cout << endl;
    m = {{1, 0},
         {1, 1}};
    cout << "max rectangle area : " << maxarea(m) << endl;

    return 0;
}