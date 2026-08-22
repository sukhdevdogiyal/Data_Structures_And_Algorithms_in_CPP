// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/description/

// Time Complexity: O(n + m)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
    vector<int> counts(26, 0);
    vector<int> countt(26, 0);

    // Count s
    for (int i = 0; i < s.size(); i++)
        counts[s[i] - 'a']++;

    // Count t
    for (int i = 0; i < t.size(); i++)
        countt[t[i] - 'a']++;

    // Compare both counts
    for (int i = 0; i < 26; i++) {
        if (counts[i] != countt[i])
            return false;
    }

    return true;
}

int main() {

    // Case 1
    string s1 = "anagram";
    string t1 = "nagaram";

    cout << "Case 1" << endl;
    cout << "s: " << s1 << endl;
    cout << "t: " << t1 << endl;
    cout << "Output: " << isAnagram(s1, t1) << endl;

    cout << endl;

    // Case 2
    string s2 = "rat";
    string t2 = "car";

    cout << "Case 2" << endl;
    cout << "s: " << s2 << endl;
    cout << "t: " << t2 << endl;
    cout << "Output: " << isAnagram(s2, t2) << endl;

    return 0;
}
