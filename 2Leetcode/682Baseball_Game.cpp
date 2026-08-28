// 682. Baseball Game

// https://leetcode.com/problems/baseball-game/description/

// Method 1: Stack Simulation

// Time Complexity: O(n)

// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

// =====================================================
// METHOD 1: STACK SIMULATION
// =====================================================

int calPoints(vector<string>& operations) {

    stack<int> st;
    int n = operations.size();

    for (int i = 0; i < n; i++) {

        string s = operations[i];

        if (s == "+") {

            int first = st.top();
            st.pop();

            int second = st.top();

            st.push(first);
            st.push(first + second);
        }

        else if (s == "D") {

            st.push(2 * st.top());
        }

        else if (s == "C") {

            st.pop();
        }

        else {
            /*
            st.push(stoi(s)) // it convert string to interger
            */

            // String to Integer - Manual Conversion

            int ele = 0;
            bool negative = false;

            for (int j = 0; j < s.size(); j++) {

                if (j == 0 && s[j] == '-') {
                    negative = true;
                }
                else {
                    ele = ele * 10 + (s[j] - '0');
                }
            }

            if (negative)
                ele = -ele;

            st.push(ele);
        }
    }

    int totalPoints = 0;

    while (!st.empty()) {
        totalPoints += st.top();
        st.pop();
    }

    return totalPoints;
}

// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    vector<string> op1 = {"5","2","C","D","+"};

    cout << "CASE 1" << endl;
    cout << "Total Points: " << calPoints(op1) << endl;

    cout << endl;

    // ================= CASE 2 =================

    vector<string> op2 = {"5","-2","4","C","D","9","+","+"};

    cout << "CASE 2" << endl;
    cout << "Total Points: " << calPoints(op2) << endl;

    cout << endl;

    // ================= CASE 3 =================

    vector<string> op3 = {"1","C"};

    cout << "CASE 3" << endl;
    cout << "Total Points: " << calPoints(op3) << endl;

    cout << endl;

    // ================= CASE 4 =================

    vector<string> op4 = {"10","20","D","+","C","5"};

    cout << "CASE 4" << endl;
    cout << "Total Points: " << calPoints(op4) << endl;

    return 0;
}