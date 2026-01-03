// first non repeating character in a stream
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

string first_non_re(string &s)
{
    string ans = "";
    unordered_map<char, int> count;
    queue<char> q;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // increse count
        count[ch]++;

        // push in queue
        q.push(ch);

        // remove repeating character
        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
                break;
        }
        if (q.empty())
            ans.push_back('#');
        else
            ans.push_back(q.front());
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    string s = "aa";
    cout << "input string : " << s << endl;
    string ans = first_non_re(s);
    cout << "first non repeating ch : " << ans << endl;

    cout << endl;
    s = "aabcb";
    cout << "input string : " << s << endl;
    ans = first_non_re(s);
    cout << "first non repeating ch : " << ans << endl;
    return 0;
}
