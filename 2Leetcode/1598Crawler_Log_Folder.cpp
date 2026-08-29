// 1598. Crawler Log Folder

// https://leetcode.com/problems/crawler-log-folder/description/

// Method 1: Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

// Method 2: Counter
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// =====================================================
// METHOD 1: STACK
// =====================================================

int minOperations_Stack(vector<string>& logs) {

    stack<bool> st;

    for (int i = 0; i < logs.size(); i++) {

        if (logs[i] == "./") {

            continue;
        }

        else if (logs[i] == "../") {

            if (!st.empty())
                st.pop();
        }

        else {

            st.push(true);
        }
    }

    return st.size();
}


// =====================================================
// METHOD 2: COUNTER
// =====================================================

int minOperations_Counter(vector<string>& logs) {

    int depth = 0;

    for (int i = 0; i < logs.size(); i++) {

        if (logs[i] == "./") {

            continue;
        }

        else if (logs[i] == "../") {

            if (depth > 0)
                depth--;
        }

        else {

            depth++;
        }
    }

    return depth;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    vector<string> logs1 = {
        "d1/",
        "d2/",
        "../",
        "d21/",
        "./"
    };

    cout << "CASE 1" << endl;

    cout << "Method 1 (Stack): "
         << minOperations_Stack(logs1) << endl;

    cout << "Method 2 (Counter): "
         << minOperations_Counter(logs1) << endl;

    cout << endl;


    // ================= CASE 2 =================

    vector<string> logs2 = {
        "d1/",
        "d2/",
        "d3/",
        "../",
        "../",
        "../"
    };

    cout << "CASE 2" << endl;

    cout << "Method 1 (Stack): "
         << minOperations_Stack(logs2) << endl;

    cout << "Method 2 (Counter): "
         << minOperations_Counter(logs2) << endl;

    cout << endl;


    // ================= CASE 3 =================

    vector<string> logs3 = {
        "d1/",
        "../",
        "../",
        "../"
    };

    cout << "CASE 3" << endl;

    cout << "Method 1 (Stack): "
         << minOperations_Stack(logs3) << endl;

    cout << "Method 2 (Counter): "
         << minOperations_Counter(logs3) << endl;

    cout << endl;


    // ================= CASE 4 =================

    vector<string> logs4 = {
        "d1/",
        "d2/",
        "d3/"
    };

    cout << "CASE 4" << endl;

    cout << "Method 1 (Stack): "
         << minOperations_Stack(logs4) << endl;

    cout << "Method 2 (Counter): "
         << minOperations_Counter(logs4) << endl;


    return 0;
}