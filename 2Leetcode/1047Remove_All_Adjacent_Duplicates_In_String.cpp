// 1047. Remove All Adjacent Duplicates In String

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

// Method 1: Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

// Method 2: String as Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

// Method 3: String Erase
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

// =====================================================
// METHOD 1: STACK
// =====================================================

string removeDuplicates_Stack(string s) {

    stack<char> st;

    for (int i = 0; i < s.size(); i++) {

        if (!st.empty() && st.top() == s[i])
            st.pop();
        else
            st.push(s[i]);
    }

    string ans;

    while (!st.empty()) {

        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


// =====================================================
// METHOD 2: STRING AS STACK
// =====================================================

string removeDuplicates_String(string s) {

    string ans;

    for (int i = 0; i < s.size(); i++) {

        if (!ans.empty() && ans.back() == s[i])
            ans.pop_back();
        else
            ans.push_back(s[i]);
    }

    return ans;
}


// =====================================================
// METHOD 3: STRING ERASE
// =====================================================

string removeDuplicates_Erase(string s) {

    int i = 0;

    while (i < s.length() - 1) {

        if (s[i] == s[i + 1]) {

            // Remove two adjacent duplicate characters
            s.erase(i, 2);

            // Check previous position
            if (i != 0)
                i--;
        }
        else {
            i++;
        }

        if (s.empty())
            break;
    }

    return s;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    string s1 = "abbaca";

    cout << "CASE 1" << endl;
    cout << "String: " << s1 << endl;

    cout << "Method 1 (Stack): "
         << removeDuplicates_Stack(s1) << endl;

    cout << "Method 2 (String as Stack): "
         << removeDuplicates_String(s1) << endl;

    cout << "Method 3 (String Erase): "
         << removeDuplicates_Erase(s1) << endl;

    cout << endl;


    // ================= CASE 2 =================

    string s2 = "azxxzy";

    cout << "CASE 2" << endl;
    cout << "String: " << s2 << endl;

    cout << "Method 1 (Stack): "
         << removeDuplicates_Stack(s2) << endl;

    cout << "Method 2 (String as Stack): "
         << removeDuplicates_String(s2) << endl;

    cout << "Method 3 (String Erase): "
         << removeDuplicates_Erase(s2) << endl;

    cout << endl;


    // ================= CASE 3 =================

    string s3 = "aabbcc";

    cout << "CASE 3" << endl;
    cout << "String: " << s3 << endl;

    cout << "Method 1 (Stack): "
         << removeDuplicates_Stack(s3) << endl;

    cout << "Method 2 (String as Stack): "
         << removeDuplicates_String(s3) << endl;

    cout << "Method 3 (String Erase): "
         << removeDuplicates_Erase(s3) << endl;

    cout << endl;


    // ================= CASE 4 =================

    string s4 = "abcddcba";

    cout << "CASE 4" << endl;
    cout << "String: " << s4 << endl;

    cout << "Method 1 (Stack): "
         << removeDuplicates_Stack(s4) << endl;

    cout << "Method 2 (String as Stack): "
         << removeDuplicates_String(s4) << endl;

    cout << "Method 3 (String Erase): "
         << removeDuplicates_Erase(s4) << endl;


    return 0;
}