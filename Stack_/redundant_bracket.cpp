#include <iostream>
#include <stack>
using namespace std;
bool findredundantbracket(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            s.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isredundant = true;
                while (!s.empty())
                {
                    char top = s.top();
                    if (top == '(')
                        break;
                    else
                        isredundant = false;
                    s.pop();
                }
                if (isredundant == true)
                    return true;
                s.pop();
            }
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    string str = "((a+b))";
    cout << "str = " << str << endl;
    if (findredundantbracket(str))
        cout << "Redundent Bracket is present" << endl;
    else
        cout << "Redundent Bracket is NOT present" << endl;

    cout << endl;
    str = "(a+(b*c))";
    cout << "str = " << str << endl;
    if (findredundantbracket(str))
        cout << "Redundent Bracket is present" << endl;
    else
        cout << "Redundent Bracket is NOT present" << endl;

    cout << endl;
    str = "(a+b*c)+(c)";
    cout << "str = " << str << endl;
    if (findredundantbracket(str))
        cout << "Redundent Bracket is present" << endl;
    else
        cout << "Redundent Bracket is NOT present" << endl;

    return 0;
}
