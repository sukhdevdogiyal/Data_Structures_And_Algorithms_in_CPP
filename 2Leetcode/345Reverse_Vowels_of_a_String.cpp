#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

string reverseVowels(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {

        // Find left vowel
        while (left < right && !isVowel(s[left])) {
            left++;
        }

        // Find right vowel
        while (left < right && !isVowel(s[right])) {
            right--;
        }

        // Swap vowels
        if (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    return s;
}

int main() {

    // Case 1
    string s1 = "IceCreAm";

    cout << "Case 1" << endl;
    cout << "Input: " << s1 << endl;
    cout << "Output: " << reverseVowels(s1) << endl;

    cout << endl;

    // Case 2
    string s2 = "leetcode";

    cout << "Case 2" << endl;
    cout << "Input: " << s2 << endl;
    cout << "Output: " << reverseVowels(s2) << endl;

    return 0;
}
