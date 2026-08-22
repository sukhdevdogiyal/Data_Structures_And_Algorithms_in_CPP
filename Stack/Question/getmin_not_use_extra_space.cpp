#include <iostream>
#include <stack>
using namespace std;

class SpecialStack
{
    int min;
    stack<int> s;

public:
    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            min = data;
        }
        else
        {
            if (data > min)
            {
                s.push(data);
            }
            else
            {
                int val = 2 * data - min;
                min = data;
                s.push(val);
            }
        }
    }
    int pop()
    {
        if (s.empty())
            return -1;

        int curr = s.top();
        s.pop();
        if (curr > min)
        {
            return curr;
        }
        else
        {
            int prevmin = min;
            int val = 2 * min - curr;
            min = val;
            return prevmin;
        }
    }
    int top()
    {
        if (s.empty())
            return -1;
        if (s.top() > min)
            return s.top();
        return min;
    }
    int getmin()
    {
        if (s.empty())
            return -1;
        return min;
    }
};
int main(int argc, char const *argv[])
{
    SpecialStack s1;
    cout << "push 5 in stack " << endl;
    s1.push(5);
    cout << "getmin = " << s1.getmin() << endl;
    cout << "push 3 in stack " << endl;
    s1.push(3);
    cout << "getmin = " << s1.getmin() << endl;
    cout << "push 8 in stack " << endl;
    s1.push(8);
    cout << "getmin = " << s1.getmin() << endl;
    cout << "push 2 in stack " << endl;
    s1.push(2);
    cout << "getmin = " << s1.getmin() << endl;
    cout << "push 4 in stack " << endl;
    s1.push(4);
    cout << "getmin = " << s1.getmin() << endl;

    cout << endl;
    cout << "pop = " << s1.pop() << endl;
    cout << "getmin = " << s1.getmin() << endl;
    cout << "pop = " << s1.pop() << endl;
    cout << "getmin = " << s1.getmin() << endl;
    cout << "pop = " << s1.pop() << endl;
    cout << "getmin = " << s1.getmin() << endl;

    return 0;
}
