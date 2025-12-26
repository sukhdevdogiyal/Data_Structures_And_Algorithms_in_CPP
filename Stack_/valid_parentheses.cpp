#include <iostream>
#include <stack>
using namespace std;
bool check(string input)
{
    stack<char> s;
    for (int i = 0; input[i] != '\0'; i++)
    {
        int ch = input[i];
        if (ch == '{' || ch == '(' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            if (s.empty())
                return false;
            int top = s.top();
            if ((top == '{' && ch == '}') || (top == '(' && ch == ')' || (top == '[' && ch == ']')))
            {
                s.pop();
            }
            else
                return false;
        }
    }
    if (s.empty())
        return true;
    else
        false;
}
int main(int argc, char const *argv[])

{
    string input = "[()]{}{[()()]()}";
    cout<<"input : "<<input<<endl;
    if (check(input))
    cout << "Balanced" << endl;
    else
    cout << "Not Balanced" << endl;
    
    input = "[[}[";
    cout<<"input : "<<input<<endl;
    if (check(input))
    cout << "Balanced" << endl;
    else
    cout << "Not Balanced" << endl;
    
    input = ")}]})";
    cout<<"input : "<<input<<endl;
    if (check(input))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}
