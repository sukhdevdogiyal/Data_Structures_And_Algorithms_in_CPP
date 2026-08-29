// 844. Backspace String Compare

// https://leetcode.com/problems/backspace-string-compare/description/

// Method 1: Stack
// Time Complexity: O(n + m)
// Space Complexity: O(n + m)

// Method 2: Two Pointer
// Time Complexity: O(n + m)
// Space Complexity: O(1)

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// =====================================================
// METHOD 1: STACK
// =====================================================

bool backspaceCompare_Stack(string s, string t) {

    stack<char> a;
    stack<char> b;

    // Process string s
    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '#') {

            if (!a.empty())
                a.pop();
        }
        else {
            a.push(s[i]);
        }
    }

    // Process string t
    for (int i = 0; i < t.size(); i++) {

        if (t[i] == '#') {

            if (!b.empty())
                b.pop();
        }
        else {
            b.push(t[i]);
        }
    }

    // Compare both stacks
    while (!a.empty() && !b.empty()) {

        if (a.top() != b.top())
            return false;

        a.pop();
        b.pop();
    }

    return a.size() == b.size();
}


// =====================================================
// METHOD 2: TWO POINTER
// =====================================================

bool backspaceCompare_TwoPointer(string s, string t) {

    int i = s.size() - 1;
    int j = t.size() - 1;

    int skipS = 0;
    int skipT = 0;

    while (i >= 0 || j >= 0) {

        // Find next valid character in s
        while (i >= 0) {

            if (s[i] == '#') {
                skipS++;
                i--;
            }
            else if (skipS > 0) {
                skipS--;
                i--;
            }
            else {
                break;
            }
        }

        // Find next valid character in t
        while (j >= 0) {

            if (t[j] == '#') {
                skipT++;
                j--;
            }
            else if (skipT > 0) {
                skipT--;
                j--;
            }
            else {
                break;
            }
        }

        // Compare valid characters
        if (i >= 0 && j >= 0) {

            if (s[i] != t[j])
                return false;
        }

        // One string has character, other doesn't
        if ((i >= 0) != (j >= 0))
            return false;

        i--;
        j--;
    }

    return true;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    string s1 = "ab#c";
    string t1 = "ad#c";

    cout << "CASE 1" << endl;
    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << t1 << endl;

    cout << "Method 1 (Stack): "
         << backspaceCompare_Stack(s1, t1) << endl;

    cout << "Method 2 (Two Pointer): "
         << backspaceCompare_TwoPointer(s1, t1) << endl;

    cout << endl;


    // ================= CASE 2 =================

    string s2 = "ab##";
    string t2 = "c#d#";

    cout << "CASE 2" << endl;
    cout << "String 1: " << s2 << endl;
    cout << "String 2: " << t2 << endl;

    cout << "Method 1 (Stack): "
         << backspaceCompare_Stack(s2, t2) << endl;

    cout << "Method 2 (Two Pointer): "
         << backspaceCompare_TwoPointer(s2, t2) << endl;

    cout << endl;


    // ================= CASE 3 =================

    string s3 = "a#c";
    string t3 = "b";

    cout << "CASE 3" << endl;
    cout << "String 1: " << s3 << endl;
    cout << "String 2: " << t3 << endl;

    cout << "Method 1 (Stack): "
         << backspaceCompare_Stack(s3, t3) << endl;

    cout << "Method 2 (Two Pointer): "
         << backspaceCompare_TwoPointer(s3, t3) << endl;

    cout << endl;


    // ================= CASE 4 =================

    string s4 = "abc###";
    string t4 = "###";

    cout << "CASE 4" << endl;
    cout << "String 1: " << s4 << endl;
    cout << "String 2: " << t4 << endl;

    cout << "Method 1 (Stack): "
         << backspaceCompare_Stack(s4, t4) << endl;

    cout << "Method 2 (Two Pointer): "
         << backspaceCompare_TwoPointer(s4, t4) << endl;


    return 0;
}