#include <iostream>
#include <stack>
using namespace std;
void insertatbottom(stack<int> &s, int x)
{
    // base case
    if (s.empty())
    {
        s.push(x);
        return;
    }

    // top element
    int num = s.top();
    s.pop();

    // recursion call
    insertatbottom(s, x);
    s.push(num);
}
void reversestack(stack<int> &s)
{
    // base case
    if (s.empty())
        return;

    // top element
    int num = s.top();
    s.pop();

    // rercusion call
    reversestack(s);

    // insert at bottom
    insertatbottom(s, num);
}
void print(stack<int> s)
{
    cout << "Top to bottom : ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    stack<int> input;
    input.push(1);
    input.push(2);
    input.push(3);
    input.push(4);
    input.push(5);

    cout << "\nBefor reverse stack : " << endl;
    print(input);

    reversestack(input);
    cout << "\nAfter reverse stack : " << endl;
    print(input);

    cout << endl;

    return 0;
}
