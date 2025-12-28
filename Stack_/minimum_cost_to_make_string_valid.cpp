#include <iostream>
#include <stack>
using namespace std;

int mincost(string str)
{
    if (str.length() % 2 == 1)
        return -1;

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
            s.push(ch);
        else
        {
            // ch is }
            if (s.empty())
                s.push(ch);
            else
            {
                if (s.top() == '{')
                    s.pop();
                else
                    s.push(ch);
            }
        }
    }

    // stack is contain invalid bracket
    int a = 0;
    int b = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
            a++;
        else
            b++;
        s.pop();
    }
    return (a + 1) / 2 + (b + 1) / 2;
}
int main(int argc, char const *argv[])
{
    string str = "{{{}";
    cout << "str = " << str << endl;
    cout << "Minimum cost to make string valid = " << mincost(str) << endl
         << endl;

    str = "{{}{}}";
    cout << "str = " << str << endl;
    cout << "Minimum cost to make string valid = " << mincost(str) << endl
         << endl;

    str = "{{{}}";
    cout << "str = " << str << endl;
    cout << "Minimum cost to make string valid = " << mincost(str) << endl
         << endl;

    str = "}}}}";
    cout << "str = " << str << endl;
    cout << "Minimum cost to make string valid = " << mincost(str) << endl
         << endl;

    str = "{}}{}{";
    cout << "str = " << str << endl;
    cout << "Minimum cost to make string valid = " << mincost(str) << endl
         << endl;

    str = "}{}}{}{{}{";
    cout << "str = " << str << endl;
    cout << "Minimum cost to make string valid = " << mincost(str) << endl
         << endl;
    return 0;
}
