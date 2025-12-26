#include <iostream>
using namespace std;
class Stack
{
    // proparties
private:
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // behavier
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // push
    void push1(int data)
    {
        if ((top1+1)<top2)
        {
            top1++;
            arr[top1] = data;
        }
        else
        {
            cout << "Stack is overflow" << endl;
        }
    }
    void push2(int data)
    {
        if (top1<(top2-1))
        {
            top2--;
            arr[top2] = data;
        }
        else
        {
            cout << "Stack is overflow" << endl;
        }
    }

    // pop
    void pop1()
    {
        if (top1 >= 0)
        {
            top1--;
        }
        else
        {
            cout << "Stack is underflow" << endl;
        }
    }
    void pop2()
    {
        if (top2 < size)
        {
            top2++;
        }
        else
        {
            cout << "Stack is underflow" << endl;
        }
    }

    
};

int main(int argc, char const *argv[])
{
    Stack s = Stack(5);
    s.pop1();
    s.pop2();
    s.push1(5);
    s.push1(23);
    s.push2(3);
    s.push2(33);
    s.push1(35);
    s.push2(2);
    return 0;
}
