// 14. Longest Common Prefix
//  https://leetcode.com/problems/longest-common-prefix/description/

#include <iostream>
#include <vector>
using namespace std;

// Approach #1
string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    for (int i = 0; i < strs[0].size(); i++)
    {
        for (int j = 0; j < strs.size(); j++)
        {
            if (strs[0][i] != strs[j][i])
                return ans;
        }
        ans.push_back(strs[0][i]);
    }
    return ans;
}

// Approch #2
// Using Trie
class TrieNode
{
public:
    bool isTerminal;
    TrieNode *child[26];
    int count;
    TrieNode()
    {
        isTerminal = false;
        count = 0;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode *node = root;
        for (auto ch : word)
        {
            int index = ch - 'a';
            if (node->child[index] == NULL)
            {
                node->count++;
                node->child[index] = new TrieNode();
            }
            node = node->child[index];
        }
        node->isTerminal = true;
    }

    string search()
    {
        TrieNode *node = root;
        string ans;
        while (node->count == 1 && !node->isTerminal)
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->child[i])
                {
                    ans.push_back(i + 'a');
                    node = node->child[i];
                    break;
                }
            }
        }
        return ans;
    }
};
string longestCommonPrefix1(vector<string> &strs)
{
    Trie *t1 = new Trie();
    for (int i = 0; i < strs.size(); i++)
    {
        t1->insert(strs[i]);
    }
    return t1->search();
}
int main(int argc, char const *argv[])
{
    vector<string> strs;
    strs = {"flower", "flow", "flight"};
    cout << "Longest common prefix : " << longestCommonPrefix(strs) << endl;
    cout << "Longest common prefix : " << longestCommonPrefix1(strs) << endl;
    cout << endl;

    strs = {"dog", "racecar", "car"};
    cout << "Longest common prefix : " << longestCommonPrefix(strs) << endl;
    cout << "Longest common prefix : " << longestCommonPrefix1(strs) << endl;

    return 0;
}
