#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void reverse(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
void reverse1(queue<int> &q)
{
    // base case
    if (q.empty())
        return;

    int e = q.front();
    q.pop();
    reverse1(q);
    q.push(e);
}
void print(queue<int> q)
{
    cout << "Queue : ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(7);
    q.push(6);
    cout << "Befor reverse ";
    print(q);
    reverse(q);
    cout << "After reverse ";
    print(q);
    reverse1(q);
    cout << "After reverse1 ";
    print(q);
    return 0;
}
