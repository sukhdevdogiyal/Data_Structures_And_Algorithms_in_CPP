// 2942. Find Words Containing Character

#include <iostream>
#include <vector>

using namespace std;

vector<int> findWordsContaining(vector<string> &words, char x)
{
    vector<int> ans;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[i].size(); j++)
        {
            if (x == words[i][j])
            {
                ans.push_back(i);
                break;
            }
        }
    }
    return ans;
}
int main()
{
    // vector<string> words = {"abc","bcd","aaaa","cbc"};
    // vector<string> words = {"abc","bcd","aaaa","cbc"};
    // vector<string> words = {"leet","code"};
    vector<string> words = {};
    // char x = 'a';
    // char x = 'z';
    char x = 'e';
    vector<int> ans = findWordsContaining(words, x);
    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
