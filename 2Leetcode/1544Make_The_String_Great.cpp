// 1544. Make The String Great

// https://leetcode.com/problems/make-the-string-great/description/

// Method 1: String as Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

// Method 2: ASCII Difference
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <string>

using namespace std;

// =====================================================
// METHOD 1: STRING AS STACK
// =====================================================

string makeGood_String(string s) {

    string ans;

    for (int i = 0; i < s.size(); i++) {

        if (!ans.empty() &&
            ((s[i] >= 'a' && s[i] <= 'z' &&
              ans.back() == s[i] - 32) ||
             (s[i] >= 'A' && s[i] <= 'Z' &&
              ans.back() == s[i] + 32))) {

            ans.pop_back();
        }
        else {

            ans.push_back(s[i]);
        }
    }

    return ans;
}


// =====================================================
// METHOD 2: ASCII DIFFERENCE
// =====================================================

string makeGood_ASCII(string s) {

    string ans;

    for (int i = 0; i < s.size(); i++) {

        if (!ans.empty() &&
            abs(s[i] - ans.back()) == 32) {

            ans.pop_back();
        }
        else {

            ans.push_back(s[i]);
        }
    }

    return ans;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    string s1 = "leEeetcode";

    cout << "CASE 1" << endl;
    cout << "String: " << s1 << endl;

    cout << "Method 1 (String as Stack): "
         << makeGood_String(s1) << endl;

    cout << "Method 2 (ASCII Difference): "
         << makeGood_ASCII(s1) << endl;

    cout << endl;


    // ================= CASE 2 =================

    string s2 = "abBAcC";

    cout << "CASE 2" << endl;
    cout << "String: " << s2 << endl;

    cout << "Method 1 (String as Stack): "
         << makeGood_String(s2) << endl;

    cout << "Method 2 (ASCII Difference): "
         << makeGood_ASCII(s2) << endl;

    cout << endl;


    // ================= CASE 3 =================

    string s3 = "s";

    cout << "CASE 3" << endl;
    cout << "String: " << s3 << endl;

    cout << "Method 1 (String as Stack): "
         << makeGood_String(s3) << endl;

    cout << "Method 2 (ASCII Difference): "
         << makeGood_ASCII(s3) << endl;

    cout << endl;


    // ================= CASE 4 =================

    string s4 = "Pp";

    cout << "CASE 4" << endl;
    cout << "String: " << s4 << endl;

    cout << "Method 1 (String as Stack): "
         << makeGood_String(s4) << endl;

    cout << "Method 2 (ASCII Difference): "
         << makeGood_ASCII(s4) << endl;

    cout << endl;


    // ================= CASE 5 =================

    string s5 = "aAbBcCdD";

    cout << "CASE 5" << endl;
    cout << "String: " << s5 << endl;

    cout << "Method 1 (String as Stack): "
         << makeGood_String(s5) << endl;

    cout << "Method 2 (ASCII Difference): "
         << makeGood_ASCII(s5) << endl;


    return 0;
}