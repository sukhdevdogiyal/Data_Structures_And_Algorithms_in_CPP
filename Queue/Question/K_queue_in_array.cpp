#include <iostream>
using namespace std;
class Kqueue
{
    int *arr;
    int s, k;
    int *rear;
    int *front;
    int *next;
    int freespot;

public:
    Kqueue(int n, int k)
    {
        s = n;
        this->k = k;
        arr = new int[s];
        rear = new int[k];
        front = new int[k];
        next = new int[s];

        for (int i = 0; i < k; i++)
        {
            rear[i] = front[i] = -1;
        }
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        next[s - 1] = -1;

        freespot = 0;
    }
    void push(int x, int qn)
    {
        // check queue is full
        if (freespot == -1)
        {
            cout << "Queue is full" << endl;
            return;
        }

        // find index
        int index = freespot;

        // store element
        arr[index] = x;

        // update freespot
        freespot = next[index];

        // update next
        next[index] = -1;

        // check it is first element
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            next[rear[qn - 1]] = index;
        }
        rear[qn - 1] = index;
    }

    int pop(int qn)
    {
        if (front[qn - 1] == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        // find index
        int index = front[qn - 1];

        // update front
        front[qn - 1] = next[index];

        // update next
        next[index] = freespot;

        // update freespot
        freespot = index;

        // one element in queue
        if (front[qn - 1] == -1)
        {
            rear[qn - 1] = -1;
        }

        return arr[index];
    }
};
int main(int argc, char const *argv[])
{
    Kqueue q = Kqueue(5, 3);
    cout << "push 10 in q1 " << endl;
    q.push(10, 1);
    cout << "push 20 in q2 " << endl;
    q.push(20, 2);
    cout << "push 30 in q1 " << endl;
    q.push(30, 1);
    cout << "push 40 in q1 " << endl;
    q.push(40, 1);
    cout << "push 50 in q2 " << endl;
    q.push(50, 2);
    cout << "pop q1 element = " << q.pop(1) << endl;
    cout << "push 50 in q1 " << endl;
    q.push(50, 1);
    return 0;
}