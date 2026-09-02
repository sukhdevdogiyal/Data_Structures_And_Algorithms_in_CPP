// 496. Next Greater Element I

// https://leetcode.com/problems/next-greater-element-i/description/

// Method 1: Brute Force
// Time Complexity: O(n1 * n2)
// Space Complexity: O(n1)

// Method 2: Monotonic Stack + Linear Search
// Time Complexity: O(n1 * n2)
// Space Complexity: O(n2)

// Method 3: Monotonic Stack + Hash Map
// Time Complexity: O(n1 + n2)
// Space Complexity: O(n2)

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// =====================================================
// METHOD 1: BRUTE FORCE
// =====================================================

vector<int> nextGreaterElement_BruteForce(
    vector<int>& nums1,
    vector<int>& nums2) {

    int n1 = nums1.size();
    int n2 = nums2.size();

    vector<int> ans;

    for (int i = 0; i < n1; i++) {

        int ele = nums1[i];
        int index = -1;

        // Find element in nums2
        for (int j = 0; j < n2; j++) {

            if (nums2[j] == ele) {
                index = j;
                break;
            }
        }

        // Find next greater element
        int greater = -1;

        for (int j = index + 1; j < n2; j++) {

            if (nums2[j] > ele) {

                greater = nums2[j];
                break;
            }
        }

        ans.push_back(greater);
    }

    return ans;
}


// =====================================================
// METHOD 2: MONOTONIC STACK + LINEAR SEARCH
// =====================================================

vector<int> nextGreaterElement_Stack(
    vector<int>& nums1,
    vector<int>& nums2) {

    int n1 = nums1.size();
    int n2 = nums2.size();

    vector<int> next(n2, -1);

    stack<int> st;

    st.push(-1);

    // Find next greater for nums2
    for (int i = n2 - 1; i >= 0; i--) {

        while (st.top() != -1 &&
               st.top() < nums2[i]) {

            st.pop();
        }

        next[i] = st.top();

        st.push(nums2[i]);
    }

    vector<int> ans;

    // Find nums1 elements in nums2
    for (int i = 0; i < n1; i++) {

        int ele = nums1[i];

        for (int j = 0; j < n2; j++) {

            if (ele == nums2[j]) {

                ans.push_back(next[j]);
                break;
            }
        }
    }

    return ans;
}


// =====================================================
// METHOD 3: MONOTONIC STACK + HASH MAP
// =====================================================

vector<int> nextGreaterElement_HashMap(
    vector<int>& nums1,
    vector<int>& nums2) {

    int n2 = nums2.size();

    stack<int> st;

    unordered_map<int, int> nextGreater;

    // Find next greater elements in nums2
    for (int i = n2 - 1; i >= 0; i--) {

        while (!st.empty() &&
               st.top() < nums2[i]) {

            st.pop();
        }

        if (st.empty())
            nextGreater[nums2[i]] = -1;
        else
            nextGreater[nums2[i]] = st.top();

        st.push(nums2[i]);
    }

    vector<int> ans;

    // Directly find answer using map
    for (int i = 0; i < nums1.size(); i++) {

        ans.push_back(nextGreater[nums1[i]]);
    }

    return ans;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    cout << "CASE 1" << endl;

    cout << "Nums1: ";

    for (int x : nums1)
        cout << x << " ";

    cout << endl;

    cout << "Nums2: ";

    for (int x : nums2)
        cout << x << " ";

    cout << endl;

    vector<int> ans1 =
        nextGreaterElement_BruteForce(nums1, nums2);

    cout << "Method 1 (Brute Force): ";

    for (int x : ans1)
        cout << x << " ";

    cout << endl;

    vector<int> ans2 =
        nextGreaterElement_Stack(nums1, nums2);

    cout << "Method 2 (Stack + Linear Search): ";

    for (int x : ans2)
        cout << x << " ";

    cout << endl;

    vector<int> ans3 =
        nextGreaterElement_HashMap(nums1, nums2);

    cout << "Method 3 (Stack + Hash Map): ";

    for (int x : ans3)
        cout << x << " ";

    cout << endl << endl;


    // ================= CASE 2 =================

    vector<int> nums3 = {2, 4};
    vector<int> nums4 = {1, 2, 3, 4};

    cout << "CASE 2" << endl;

    cout << "Nums1: ";

    for (int x : nums3)
        cout << x << " ";

    cout << endl;

    cout << "Nums2: ";

    for (int x : nums4)
        cout << x << " ";

    cout << endl;

    vector<int> ans4 =
        nextGreaterElement_BruteForce(nums3, nums4);

    cout << "Method 1 (Brute Force): ";

    for (int x : ans4)
        cout << x << " ";

    cout << endl;

    vector<int> ans5 =
        nextGreaterElement_Stack(nums3, nums4);

    cout << "Method 2 (Stack + Linear Search): ";

    for (int x : ans5)
        cout << x << " ";

    cout << endl;

    vector<int> ans6 =
        nextGreaterElement_HashMap(nums3, nums4);

    cout << "Method 3 (Stack + Hash Map): ";

    for (int x : ans6)
        cout << x << " ";

    cout << endl << endl;


    // ================= CASE 3 =================

    vector<int> nums5 = {1, 3, 5, 2, 4};
    vector<int> nums6 = {6, 5, 4, 3, 2, 1, 7};

    cout << "CASE 3" << endl;

    cout << "Nums1: ";

    for (int x : nums5)
        cout << x << " ";

    cout << endl;

    cout << "Nums2: ";

    for (int x : nums6)
        cout << x << " ";

    cout << endl;

    vector<int> ans7 =
        nextGreaterElement_BruteForce(nums5, nums6);

    cout << "Method 1 (Brute Force): ";

    for (int x : ans7)
        cout << x << " ";

    cout << endl;

    vector<int> ans8 =
        nextGreaterElement_Stack(nums5, nums6);

    cout << "Method 2 (Stack + Linear Search): ";

    for (int x : ans8)
        cout << x << " ";

    cout << endl;

    vector<int> ans9 =
        nextGreaterElement_HashMap(nums5, nums6);

    cout << "Method 3 (Stack + Hash Map): ";

    for (int x : ans9)
        cout << x << " ";

    cout << endl;


    return 0;
}