// 739. Daily Temperatures

// https://leetcode.com/problems/daily-temperatures/description/

// Method 1: Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Method 2: Monotonic Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// =====================================================
// METHOD 1: BRUTE FORCE
// =====================================================

vector<int> dailyTemperatures_BruteForce(vector<int>& temperatures) {

    int n = temperatures.size();

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            if (temperatures[j] > temperatures[i]) {

                ans[i] = j - i;
                break;
            }
        }
    }

    return ans;
}


// =====================================================
// METHOD 2: MONOTONIC STACK
// =====================================================

vector<int> dailyTemperatures_MonotonicStack(
    vector<int>& temperatures) {

    stack<int> st;

    int n = temperatures.size();

    vector<int> ans(n, 0);

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() &&
               temperatures[i] >= temperatures[st.top()]) {

            st.pop();
        }

        if (!st.empty()) {

            ans[i] = st.top() - i;
        }

        st.push(i);
    }

    return ans;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    vector<int> temperatures1 = {
        73, 74, 75, 71, 69, 72, 76, 73
    };

    cout << "CASE 1" << endl;

    cout << "Temperatures: ";

    for (int x : temperatures1)
        cout << x << " ";

    cout << endl;

    vector<int> ans1 =
        dailyTemperatures_BruteForce(temperatures1);

    cout << "Method 1 (Brute Force): ";

    for (int x : ans1)
        cout << x << " ";

    cout << endl;

    vector<int> ans2 =
        dailyTemperatures_MonotonicStack(temperatures1);

    cout << "Method 2 (Monotonic Stack): ";

    for (int x : ans2)
        cout << x << " ";

    cout << endl << endl;


    // ================= CASE 2 =================

    vector<int> temperatures2 = {
        30, 40, 50, 60
    };

    cout << "CASE 2" << endl;

    cout << "Temperatures: ";

    for (int x : temperatures2)
        cout << x << " ";

    cout << endl;

    vector<int> ans3 =
        dailyTemperatures_BruteForce(temperatures2);

    cout << "Method 1 (Brute Force): ";

    for (int x : ans3)
        cout << x << " ";

    cout << endl;

    vector<int> ans4 =
        dailyTemperatures_MonotonicStack(temperatures2);

    cout << "Method 2 (Monotonic Stack): ";

    for (int x : ans4)
        cout << x << " ";

    cout << endl << endl;


    // ================= CASE 3 =================

    vector<int> temperatures3 = {
        30, 20, 10
    };

    cout << "CASE 3" << endl;

    cout << "Temperatures: ";

    for (int x : temperatures3)
        cout << x << " ";

    cout << endl;

    vector<int> ans5 =
        dailyTemperatures_BruteForce(temperatures3);

    cout << "Method 1 (Brute Force): ";

    for (int x : ans5)
        cout << x << " ";

    cout << endl;

    vector<int> ans6 =
        dailyTemperatures_MonotonicStack(temperatures3);

    cout << "Method 2 (Monotonic Stack): ";

    for (int x : ans6)
        cout << x << " ";

    cout << endl << endl;


    // ================= CASE 4 =================

    vector<int> temperatures4 = {
        73, 73, 74, 72, 76
    };

    cout << "CASE 4" << endl;

    cout << "Temperatures: ";

    for (int x : temperatures4)
        cout << x << " ";

    cout << endl;

    vector<int> ans7 =
        dailyTemperatures_BruteForce(temperatures4);

    cout << "Method 1 (Brute Force): ";

    for (int x : ans7)
        cout << x << " ";

    cout << endl;

    vector<int> ans8 =
        dailyTemperatures_MonotonicStack(temperatures4);

    cout << "Method 2 (Monotonic Stack): ";

    for (int x : ans8)
        cout << x << " ";

    cout << endl;


    return 0;
}