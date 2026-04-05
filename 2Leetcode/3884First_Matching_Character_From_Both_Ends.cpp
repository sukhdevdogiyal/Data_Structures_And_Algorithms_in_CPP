// 3884. First Matching Character From Both Ends
// https://leetcode.com/problems/first-matching-character-from-both-ends/description/

#include <iostream>
using namespace std;
int firstMatchingIndex(string s)
{
    int i = 0;
    int ans = -1;
    int n = s.size();
    while (i <= n - i - 1)
    {
        if (s[i] == s[n - i - 1])
        {
            ans = i;
            break;
        }
        i++;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    string s = "abcacbd";
    cout<<"s : "<<s<<endl;
    cout<<"ans : ";
    cout << firstMatchingIndex(s)<<endl;

    cout<<endl;
    s = "abc";
    cout<<"s : "<<s<<endl;
    cout<<"ans : ";
    cout << firstMatchingIndex(s)<<endl;

    cout<<endl;
    s = "abcdab";
    cout<<"s : "<<s<<endl;
    cout<<"ans : ";
    cout << firstMatchingIndex(s)<<endl;
    return 0;
}
