// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/description/

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <string>
using namespace std;

int getlength(string s) {
    int count = 0;
    int i = 0;

    while (s[i] != '\0') {
        count++;
        i++;
    }

    return count;
}

char tolowercase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch;
    }
    else if (ch >= '0' && ch <= '9') {
        return ch;
    }
    else {
        return ch - 'A' + 'a';
    }
}

bool isPalindrome(string s) {
    int n = getlength(s);

    int f = 0;
    int l = n - 1;

    while (f < l) {

        if (tolowercase(s[f]) < '0' ||
            (tolowercase(s[f]) > '9' && tolowercase(s[f]) < 'a') ||
            tolowercase(s[f]) > 'z') {
            f++;
        }

        else if (tolowercase(s[l]) < '0' ||
                 (tolowercase(s[l]) > '9' && tolowercase(s[l]) < 'a') ||
                 tolowercase(s[l]) > 'z') {
            l--;
        }

        else if (tolowercase(s[f]) != tolowercase(s[l])) {
            return false;
        }

        else {
            f++;
            l--;
        }
    }

    return true;
}

int main() {

    string s1 = "A man, a plan, a canal: Panama";

    cout << "Case 1" << endl;
    cout << "Input: " << s1 << endl;
    cout << "Output: " << isPalindrome(s1) << endl;

    cout << endl;

    string s2 = "race a car";

    cout << "Case 2" << endl;
    cout << "Input: " << s2 << endl;
    cout << "Output: " << isPalindrome(s2) << endl;

    cout << endl;

    string s3 = " ";

    cout << "Case 3" << endl;
    cout << "Input: " << s3 << endl;
    cout << "Output: " << isPalindrome(s3) << endl;

    return 0;
}
