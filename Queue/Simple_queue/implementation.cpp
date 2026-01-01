#include <iostream>
using namespace std;
class Queue
{
    int rear;
    int front;
    int *arr;
    int size;

public:
    Queue(int s)
    {
        size = s;
        arr = new int[size];
        rear = 0;
        front = 0;
    }
    void push(int e)
    {
        if (rear == size)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        arr[rear] = e;
        rear++;
    }
    int pop()
    {
        if (rear == front)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int e = arr[front];
        front++;
        if (front == rear)
            front = rear = 0;
        return e;
    }
    int fronte()
    {
        if (front == rear)
            return -1;
        return arr[front];
    }
    bool empty()
    {
        if (rear == front)
            return true;
        else
            return false;
    }
};
int main(int argc, char const *argv[])
{
    Queue q = Queue(3);
    cout << "queue is empty : " << q.empty() << endl;
    q.pop();
    cout << "element 10 enqueue in queue " << endl;
    q.push(10);

    cout << "pop element in queue : " << q.pop() << endl;

    cout << "element 20 enqueue in queue " << endl;
    q.push(20);
    cout << "element 30 enqueue in queue " << endl;
    q.push(30);
    cout << "element 40 enqueue in queue " << endl;
    q.push(40);
    cout << "element 50 enqueue in queue " << endl;
    q.push(50);
    cout << "pop element in queue : " << q.pop() << endl;
    cout << "front element of queue : " << q.fronte() << endl;
    cout << "queue is empty : " << q.empty() << endl;
    return 0;
}
