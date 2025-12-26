#include <iostream>
using namespace std;
class Stack
{
    // proparties
private:
    int *arr;
    int top;
    int size;

public:
    // behavier
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // push
    void push(int data)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack is overflow" << endl;
        }
    }

    // pop
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack is underflow" << endl;
        }
    }

    // peek
    int peek()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        if (top == -1)
            return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Stack s = Stack(5);
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "peek : " << s.peek() << endl;
    s.pop();
    cout << "peek : " << s.peek() << endl;
    if (s.empty())
        cout << "stack is empty" << endl;
    else
        cout << "stack is not empty" << endl;
    return 0;
}
