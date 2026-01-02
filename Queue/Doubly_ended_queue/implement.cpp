#include <iostream>
using namespace std;
class dequeue
{
public:
    int *arr;
    int s;
    int rear;
    int front;

    dequeue(int n)
    {
        s = n;
        arr = new int[s];
        rear = front = -1;
    }
    void push_front(int x)
    {
        // check full
        if (front == 0 && rear == s - 1 || front - 1 == rear)
        {
            cout << "queue is full" << endl;
            return;
        }

        // first element push
        if (rear == -1)
        {
            rear++;
            front++;
        }
        else if (front == 0) // if front is point to first element
            front = s - 1;
        else
            front--;

        // store element
        arr[front] = x;
    }

    void push_back(int x)
    {
        // check full
        if (front == 0 && rear == s - 1 || front - 1 == rear)
        {
            cout << "queue is full" << endl;
            return;
        }

        // first element push
        if (rear == -1)
        {
            rear++;
            front++;
        }
        else if (rear == s - 1) // if rear is point to last element
            rear = 0;
        else
            rear++;

        // store element
        arr[rear] = x;
    }

    int pop_front()
    {
        // check empty
        if (front == -1)
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        // element
        int e = arr[front];
        // increase front
        front++;
        // only one element in queue
        if (rear + 1 == front)
            rear = front = -1;
        // front point last element
        if (front == s)
            front = 0;
        return e;
    }
    int pop_back()
    {
        // check empty
        if (front == -1)
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        // element
        int e = arr[rear];
        // increase front
        rear--;
        // only one element in queue
        if (rear + 1 == front)
            rear = front = -1;
        // rear point first element
        if (rear == -1 && front != -1)
            rear = s;
        return e;
    }
};
int main(int argc, char const *argv[])
{
    dequeue q = dequeue(5);
    q.pop_back();
    q.pop_front();
    cout << "push front element 10 in queue " << endl;
    q.push_front(10);
    cout << "pop front element : " << q.pop_front() << endl;
    cout << "push front element 10 in queue " << endl;
    q.push_front(10);
    cout << "push front element 20 in queue " << endl;
    q.push_front(20);
    cout << "push back element 30 in queue " << endl;
    q.push_back(30);
    cout << "front element : " << q.front << endl;
    cout << "back element : " << q.rear << endl;
    cout << "pop front element  " << q.pop_front() << endl;
    cout << "front element : " << q.front << endl;
    cout << "pop back element  " << q.pop_back() << endl;
    cout << "back element : " << q.front << endl;
    return 0;
}
