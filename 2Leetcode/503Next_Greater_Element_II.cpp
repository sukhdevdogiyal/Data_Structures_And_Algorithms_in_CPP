// 503. Next Greater Element II

// https://leetcode.com/problems/next-greater-element-ii/description/

// Method 1: Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Method 2: Monotonic Stack + Maximum Element
// Time Complexity: O(n)
// Space Complexity: O(n)

// Method 3: Monotonic Stack + 2n Traversal
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// =====================================================
// METHOD 1: BRUTE FORCE
// =====================================================

vector<int> nextGreaterElements_BruteForce(vector<int>& nums) {

    int n = nums.size();

    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {

        for (int j = 1; j < n; j++) {

            int index = (i + j) % n;

            if (nums[index] > nums[i]) {

                ans[i] = nums[index];
                break;
            }
        }
    }

    return ans;
}


// =====================================================
// METHOD 2: MONOTONIC STACK + MAXIMUM ELEMENT
// =====================================================

vector<int> nextGreaterElements_MaxElement(
    vector<int>& nums) {

    int n = nums.size();

    int maxIndex = 0;

    // Find maximum element
    for (int i = 1; i < n; i++) {

        if (nums[i] >= nums[maxIndex])
            maxIndex = i;
    }

    vector<int> ans(n, -1);

    stack<int> st;

    // Maximum element can never have
    // a greater element
    st.push(nums[maxIndex]);

    int i = maxIndex - 1;

    if (i == -1)
        i = n - 1;

    while (i != maxIndex) {

        while (!st.empty() &&
               st.top() <= nums[i]) {

            st.pop();
        }

        if (!st.empty())
            ans[i] = st.top();

        st.push(nums[i]);

        i--;

        if (i == -1)
            i = n - 1;
    }

    return ans;
}


// =====================================================
// METHOD 3: MONOTONIC STACK + 2n TRAVERSAL
// =====================================================

vector<int> nextGreaterElements_2n(
    vector<int>& nums) {

    int n = nums.size();

    vector<int> ans(n, -1);

    stack<int> st;

    // Traverse array twice
    for (int i = 2 * n - 1; i >= 0; i--) {

        int index = i % n;

        // Remove smaller or equal elements
        while (!st.empty() &&
               st.top() <= nums[index]) {

            st.pop();
        }

        // Only store answer during first traversal
        if (i < n && !st.empty()) {

            ans[index] = st.top();
        }

        st.push(nums[index]);
    }

    return ans;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    vector<int> nums1 = {1, 2, 1};

    cout << "CASE 1" << endl;

    cout << "Array: ";

    for (int x : nums1)
        cout << x << " ";

    cout << endl;

    vector<int> ans1 =
        nextGreaterElements_BruteForce(nums1);

    cout << "Method 1 (Brute Force): ";

    for (int x : ans1)
        cout << x << " ";

    cout << endl;

    vector<int> ans2 =
        nextGreaterElements_MaxElement(nums1);

    cout << "Method 2 (Max Element): ";

    for (int x : ans2)
        cout << x << " ";

    cout << endl;

    vector<int> ans3 =
        nextGreaterElements_2n(nums1);

    cout << "Method 3 (2n Traversal): ";

    for (int x : ans3)
        cout << x << " ";

    cout << endl << endl;


    // ================= CASE 2 =================

    vector<int> nums2 = {1, 2, 3, 4, 3};

    cout << "CASE 2" << endl;

    cout << "Array: ";

    for (int x : nums2)
        cout << x << " ";

    cout << endl;

    vector<int> ans4 =
        nextGreaterElements_BruteForce(nums2);

    cout << "Method 1 (Brute Force): ";

    for (int x : ans4)
        cout << x << " ";

    cout << endl;

    vector<int> ans5 =
        nextGreaterElements_MaxElement(nums2);

    cout << "Method 2 (Max Element): ";

    for (int x : ans5)
        cout << x << " ";

    cout << endl;

    vector<int> ans6 =
        nextGreaterElements_2n(nums2);

    cout << "Method 3 (2n Traversal): ";

    for (int x : ans6)
        cout << x << " ";

    cout << endl << endl;


    // ================= CASE 3 =================

    vector<int> nums3 = {5, 4, 3, 2, 1};

    cout << "CASE 3" << endl;

    cout << "Array: ";

    for (int x : nums3)
        cout << x << " ";

    cout << endl;

    vector<int> ans7 =
        nextGreaterElements_BruteForce(nums3);

    cout << "Method 1 (Brute Force): ";

    for (int x : ans7)
        cout << x << " ";

    cout << endl;

    vector<int> ans8 =
        nextGreaterElements_MaxElement(nums3);

    cout << "Method 2 (Max Element): ";

    for (int x : ans8)
        cout << x << " ";

    cout << endl;

    vector<int> ans9 =
        nextGreaterElements_2n(nums3);

    cout << "Method 3 (2n Traversal): ";

    for (int x : ans9)
        cout << x << " ";

    cout << endl << endl;


    // ================= CASE 4 =================

    vector<int> nums4 = {3, 3, 3};

    cout << "CASE 4" << endl;

    cout << "Array: ";

    for (int x : nums4)
        cout << x << " ";

    cout << endl;

    vector<int> ans10 =
        nextGreaterElements_BruteForce(nums4);

    cout << "Method 1 (Brute Force): ";

    for (int x : ans10)
        cout << x << " ";

    cout << endl;

    vector<int> ans11 =
        nextGreaterElements_MaxElement(nums4);

    cout << "Method 2 (Max Element): ";

    for (int x : ans11)
        cout << x << " ";

    cout << endl;

    vector<int> ans12 =
        nextGreaterElements_2n(nums4);

    cout << "Method 3 (2n Traversal): ";

    for (int x : ans12)
        cout << x << " ";

    cout << endl;


    return 0;
}