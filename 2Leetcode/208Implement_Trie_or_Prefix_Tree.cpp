#include <iostream>
using namespace std;
class TrieNode
{
public:
    TrieNode *child[26];
    bool isTerminal;
    TrieNode()
    {
        isTerminal = false;
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
                node->child[index] = new TrieNode();
            }
            node = node->child[index];
        }
        node->isTerminal = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (auto ch : word)
        {
            int index = ch - 'a';
            if (node->child[index] == NULL)
            {
                return false;
            }
            node = node->child[index];
        }
        return node->isTerminal;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (auto ch : prefix)
        {
            int index = ch - 'a';
            if (node->child[index] == NULL)
            {
                return false;
            }
            node = node->child[index];
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    Trie *obj = new Trie();
    obj->insert("apple");
    cout<<"apple is present in trie : "<<obj->search("apple")<<endl;
    cout<<"path app is present or not : "<<obj->startsWith("app")<<endl;
    cout<<"app is present in trie : "<<obj->search("app")<<endl;
    cout<<"path apx is present or not : "<<obj->startsWith("apx")<<endl;
    return 0;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */