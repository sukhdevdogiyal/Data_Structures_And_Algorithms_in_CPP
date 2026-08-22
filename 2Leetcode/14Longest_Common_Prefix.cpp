// Method 1: Brute Force
// Time Complexity: O(N * M)
// Space Complexity: O(M)

// Method 2: Trie
// Time Complexity: O(N * M)
// Space Complexity: O(N * M)

#include <iostream>
#include <vector>
#include <string>
using namespace std;


// =====================================================
// METHOD 1: BRUTE FORCE
// =====================================================

string longestCommonPrefix_BruteForce(vector<string>& strs) {

    string ans = "";

    for (int i = 0; i < strs[0].size(); i++) {

        for (int j = 1; j < strs.size(); j++) {

            if (i >= strs[j].size() || strs[0][i] != strs[j][i])
                return ans;
        }

        ans.push_back(strs[0][i]);
    }

    return ans;
}


// =====================================================
// METHOD 2: TRIE
// =====================================================

class TrieNode {
public:
    bool isTerminal;
    TrieNode* child[26];
    int count;

    TrieNode() {
        isTerminal = false;
        count = 0;

        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};


class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {

        TrieNode* node = root;

        for (auto ch : word) {

            int index = ch - 'a';

            if (node->child[index] == NULL) {
                node->count++;
                node->child[index] = new TrieNode();
            }

            node = node->child[index];
        }

        node->isTerminal = true;
    }


    string search() {

        TrieNode* node = root;
        string ans = "";

        while (node->count == 1 && !node->isTerminal) {

            for (int i = 0; i < 26; i++) {

                if (node->child[i]) {

                    ans.push_back(i + 'a');
                    node = node->child[i];

                    break;
                }
            }
        }

        return ans;
    }
};


string longestCommonPrefix_Trie(vector<string>& strs) {

    Trie* t1 = new Trie();

    for (int i = 0; i < strs.size(); i++) {
        t1->insert(strs[i]);
    }

    return t1->search();
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    vector<string> strs1 = {
        "flower",
        "flow",
        "flight"
    };

    cout << "CASE 1" << endl;

    cout << "Input: {flower, flow, flight}" << endl;

    cout << "Method 1 Output: "
         << longestCommonPrefix_BruteForce(strs1)
         << endl;

    cout << "Method 2 Output: "
         << longestCommonPrefix_Trie(strs1)
         << endl;


    cout << endl;


    // ================= CASE 2 =================

    vector<string> strs2 = {
        "dog",
        "racecar",
        "car"
    };

    cout << "CASE 2" << endl;

    cout << "Input: {dog, racecar, car}" << endl;

    cout << "Method 1 Output: "
         << longestCommonPrefix_BruteForce(strs2)
         << endl;

    cout << "Method 2 Output: "
         << longestCommonPrefix_Trie(strs2)
         << endl;


    cout << endl;


    // ================= CASE 3 =================

    vector<string> strs3 = {
        "interview",
        "internet",
        "internal"
    };

    cout << "CASE 3" << endl;

    cout << "Input: {interview, internet, internal}" << endl;

    cout << "Method 1 Output: "
         << longestCommonPrefix_BruteForce(strs3)
         << endl;

    cout << "Method 2 Output: "
         << longestCommonPrefix_Trie(strs3)
         << endl;


    return 0;
}
