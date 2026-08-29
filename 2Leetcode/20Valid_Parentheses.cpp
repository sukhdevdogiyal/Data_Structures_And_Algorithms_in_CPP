// 20. Valid Parentheses

// https://leetcode.com/problems/valid-parentheses/description/

// Method 1: Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

// Method 2: Vector as Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// =====================================================
// METHOD 1: STACK
// =====================================================

bool isValid_Stack(string s) {

    stack<char> st;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '(')
            st.push(')');

        else if (s[i] == '[')
            st.push(']');

        else if (s[i] == '{')
            st.push('}');

        else {

            if (st.empty())
                return false;

            if (st.top() == s[i])
                st.pop();
            else
                return false;
        }
    }

    return st.empty();
}


// =====================================================
// METHOD 2: VECTOR AS STACK
// =====================================================

bool isValid_Vector(string s) {

    vector<char> ans;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '(') {

            ans.push_back(')');
        }

        else if (s[i] == '[') {

            ans.push_back(']');
        }

        else if (s[i] == '{') {

            ans.push_back('}');
        }

        else if (!ans.empty()) {

            if (ans.back() == s[i])
                ans.pop_back();

            else
                return false;
        }

        else {

            return false;
        }
    }

    return ans.empty();
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    string s1 = "()";

    cout << "CASE 1" << endl;
    cout << "String: " << s1 << endl;

    cout << "Method 1 (Stack): "
         << isValid_Stack(s1) << endl;

    cout << "Method 2 (Vector as Stack): "
         << isValid_Vector(s1) << endl;

    cout << endl;


    // ================= CASE 2 =================

    string s2 = "()[]{}";

    cout << "CASE 2" << endl;
    cout << "String: " << s2 << endl;

    cout << "Method 1 (Stack): "
         << isValid_Stack(s2) << endl;

    cout << "Method 2 (Vector as Stack): "
         << isValid_Vector(s2) << endl;

    cout << endl;


    // ================= CASE 3 =================

    string s3 = "(]";

    cout << "CASE 3" << endl;
    cout << "String: " << s3 << endl;

    cout << "Method 1 (Stack): "
         << isValid_Stack(s3) << endl;

    cout << "Method 2 (Vector as Stack): "
         << isValid_Vector(s3) << endl;

    cout << endl;


    // ================= CASE 4 =================

    string s4 = "([{}])";

    cout << "CASE 4" << endl;
    cout << "String: " << s4 << endl;

    cout << "Method 1 (Stack): "
         << isValid_Stack(s4) << endl;

    cout << "Method 2 (Vector as Stack): "
         << isValid_Vector(s4) << endl;

    cout << endl;


    // ================= CASE 5 =================

    string s5 = "(((";

    cout << "CASE 5" << endl;
    cout << "String: " << s5 << endl;

    cout << "Method 1 (Stack): "
         << isValid_Stack(s5) << endl;

    cout << "Method 2 (Vector as Stack): "
         << isValid_Vector(s5) << endl;


    return 0;
}