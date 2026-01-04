// interleave the first half of the queue with second half

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// using queue
void interleave(queue<int> &q)
{
    queue<int> newq;
    int n = q.size() + 1;
    for (int i = 0; i < n / 2; i++)
    {
        newq.push(q.front());
        q.pop();
    }
    while (!newq.empty())
    {
        q.push(newq.front());
        newq.pop();
        q.push(q.front());
        q.pop();
    }
}

// using stack
void interleave1(queue<int> &q)
{
    stack<int> s;
    int n = q.size();
    for (int i = 0; i < n / 2; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < n / 2; i++)
    {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < n / 2; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

void print(queue<int> q)
{
    cout << "queue : ";
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
    for (int i = 11; i < 19; i++)
    {
        q.push(i);
    }

    print(q);
    interleave1(q);
    print(q);

    return 0;
}
