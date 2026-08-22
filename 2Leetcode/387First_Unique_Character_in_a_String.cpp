// 387. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/description/

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    int count[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (count[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {

    // Case 1
    string s1 = "leetcode";

    cout << "Case 1" << endl;
    cout << "Input: " << s1 << endl;
    cout << "Output: " << firstUniqChar(s1) << endl;

    cout << endl;

    // Case 2
    string s2 = "loveleetcode";

    cout << "Case 2" << endl;
    cout << "Input: " << s2 << endl;
    cout << "Output: " << firstUniqChar(s2) << endl;

    cout << endl;

    // Case 3
    string s3 = "aabb";

    cout << "Case 3" << endl;
    cout << "Input: " << s3 << endl;
    cout << "Output: " << firstUniqChar(s3) << endl;

    return 0;
}
