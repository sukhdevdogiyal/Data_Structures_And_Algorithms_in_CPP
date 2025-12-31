/*
celebrity :
1. every one knows celebrity
2. celebrity knows no one

apporch 1:
- each person check - celebrity or not
-
- check row and coloms
- 1. all row is 0's except diagnal
- 2. all coloms is 1's except diagnal
- if both condition is true person is celebrity
-
- T.C. = O(n^2);
- S.C. = O(1);

apporch 2:
- take 2 person and find it is knows each other
-
- store all person in stack
- take 2 person into stack a,b
- if a is knows b then b is push into stack
- else then a is push into the stack
- repeat until only one person in stack
- this remaining one person is cel or not
- check both 2 condition
-
- T.C. = O(n)
- S.C. = O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int knows(vector<vector<int>> &m, int a, int b)
{
    return m[a][b];
}
int findcelebrity(vector<vector<int>> &m)
{
    // store all person in stack
    stack<int> s;
    int n = m.size();
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // take two person and compare
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (knows(m, a, b))
            s.push(b);
        else
            s.push(a);
    }

    // one person in stack
    int cel = s.top();

    // check it celebrity or not
    for (int i = 0; i < n; i++)
    {
        if (i != cel && knows(m, cel, i))
            return -1;
        if (i != cel && !knows(m, i, cel))
            return -1;
    }
    return cel;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> m = {{0, 1, 0},
                             {0, 0, 0},
                             {0, 1, 0}};

    cout << "Celebrity is Person : " << findcelebrity(m) << endl;

    cout << endl;
    m = {{1, 1},
         {1, 1}};
    cout << "Celebrity is Person : " << findcelebrity(m) << endl;

    cout << endl;
    m = {{1, 0},
         {1, 1}};
    cout << "Celebrity is Person : " << findcelebrity(m) << endl;

    return 0;
}
