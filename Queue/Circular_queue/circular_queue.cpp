#include <iostream>
using namespace std;
class Circular
{
    int rear;
    int front;
    int *arr;
    int size;

public:
    Circular(int s)
    {
        size = s;
        arr = new int[size];
        rear = -1;
        front = -1;
    }
    void push(int e)
    {
        // check queue is full
        if (rear == size - 1 && front == 0 || rear + 1 == front)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        // push first element 
        if (front == -1)
            front++;
        // rear increase
        rear++;
        // if rear is last element
        if (rear == size)
            rear = 0;
        // push elemement in queue
        arr[rear] = e;
    }
    int pop()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int e = arr[front];
        front++;
        if (front == rear + 1)
            front = rear = -1;
        if (front == size)
            front = 0;
        return e;
    }
    int fronte()
    {
        if (front == -1)
            return -1;
        return arr[front];
    }
    bool empty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
};
int main(int argc, char const *argv[])
{
    Circular q = Circular(3);
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
    cout << "element 60 enqueue in queue " << endl;
    q.push(60);
    cout << "element 70 enqueue in queue " << endl;
    q.push(70);
    cout << "front element of queue : " << q.fronte() << endl;
    cout << "queue is empty : " << q.empty() << endl;
    return 0;
}
