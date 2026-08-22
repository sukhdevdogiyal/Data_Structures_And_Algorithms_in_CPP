// 383. Ransom Note
// https://leetcode.com/problems/ransom-note/description/

// Time Complexity: O(n + m)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    vector<int> countransom(26, 0);
    vector<int> countmaga(26, 0);

    // Count ransomNote
    for (int i = 0; i < ransomNote.size(); i++)
        countransom[ransomNote[i] - 'a']++;

    // Count magazine
    for (int i = 0; i < magazine.size(); i++)
        countmaga[magazine[i] - 'a']++;

    // If magazine has fewer characters than ransomNote
    for (int i = 0; i < 26; i++) {
        if (countransom[i] > countmaga[i])
            return false;
    }

    return true;
}

int main() {

    // Case 1
    string ransomNote1 = "a";
    string magazine1 = "b";

    cout << "Case 1" << endl;
    cout << "RansomNote: " << ransomNote1 << endl;
    cout << "Magazine: " << magazine1 << endl;
    cout << "Output: " << canConstruct(ransomNote1, magazine1) << endl;

    cout << endl;

    // Case 2
    string ransomNote2 = "aa";
    string magazine2 = "ab";

    cout << "Case 2" << endl;
    cout << "RansomNote: " << ransomNote2 << endl;
    cout << "Magazine: " << magazine2 << endl;
    cout << "Output: " << canConstruct(ransomNote2, magazine2) << endl;

    cout << endl;

    // Case 3
    string ransomNote3 = "aa";
    string magazine3 = "aab";

    cout << "Case 3" << endl;
    cout << "RansomNote: " << ransomNote3 << endl;
    cout << "Magazine: " << magazine3 << endl;
    cout << "Output: " << canConstruct(ransomNote3, magazine3) << endl;

    return 0;
}
