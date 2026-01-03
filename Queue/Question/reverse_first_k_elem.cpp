// reverse first k element of queue

#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void reverse(queue<int> &q, int k)
{
    if (k > q.size())
        return;
    stack<int> s;
    int i = k;
    while (i--)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    i = q.size() - k;
    while (i--)
    {
        int e = q.front();
        q.pop();
        q.push(e);
    }
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
    int k = 3;
    cout << "Befor reverse ";
    print(q);
    cout << "k = " << k << endl;
    reverse(q, k);
    cout << "After reverse ";
    print(q);
    
    return 0;
}
