#include <iostream>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        isTerminal = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    // insert function
    // T.C = O(L)
    void insertWord(string word)
    {
        TrieNode *node = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            int index = word[i] - 'a';
            if (node->children[index] == NULL)
            {
                node->children[index] = new TrieNode(word[i]);
            }
            node = node->children[index];
        }
        node->isTerminal = true;
    }

    // search
    // T.C = O(L)
    bool search(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        if (root->children[word[0] - 'a'])
        {
            return search(root->children[word[0] - 'a'], word.substr(1));
        }
        else
        {
            return false;
        }
    }
    bool searchWord(string word)
    {
        return search(root, word);
    }
};
int main(int argc, char const *argv[])
{
    Trie *t = new Trie();
    t->insertWord("arm");
    t->insertWord("cat");
    t->insertWord("du");
    t->insertWord("time");
    cout << "String \"cat\" present in Trie : " << t->searchWord("cat") << endl;
    cout << "String \"dog\" present in Trie : " << t->searchWord("dog") << endl;
    cout << "String \"time\" present in Trie : " << t->searchWord("time") << endl;
    return 0;
}
