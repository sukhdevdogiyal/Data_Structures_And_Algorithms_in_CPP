// 239. Sliding Window Maximum

// https://leetcode.com/problems/sliding-window-maximum/

// Method 1: Monotonic Deque
// Time Complexity: O(n)
// Space Complexity: O(k)

// Method 2: Brute Force
// Time Complexity: O(n * k)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// =====================================================
// METHOD 1: MONOTONIC DEQUE
// =====================================================

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    deque<int> q;
    vector<int> ans;

    // ================= FIRST WINDOW =================

    for(int i = 0; i < k; i++) {

        // Remove smaller elements
        // because current element is greater
        while(!q.empty() && nums[q.back()] < nums[i])
            q.pop_back();

        q.push_back(i);
    }

    // ================= REMAINING WINDOWS =================

    for(int i = k; i < nums.size(); i++) {

        // Front contains maximum of previous window
        ans.push_back(nums[q.front()]);

        // Remove element which is outside window
        if(q.front() + k <= i)
            q.pop_front();

        // Remove smaller elements from back
        while(!q.empty() && nums[q.back()] < nums[i])
            q.pop_back();

        // Add current index
        q.push_back(i);
    }

    // ================= LAST WINDOW =================

    ans.push_back(nums[q.front()]);

    return ans;
}


// =====================================================
// METHOD 2: BRUTE FORCE
// =====================================================

vector<int> maxSlidingWindowBrute(vector<int>& nums, int k) {

    vector<int> ans;

    for(int i = 0; i <= nums.size() - k; i++) {

        int maxi = nums[i];

        for(int j = i; j < i + k; j++) {
            maxi = max(maxi, nums[j]);
        }

        ans.push_back(maxi);
    }

    return ans;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;

    vector<int> ans1 = maxSlidingWindow(nums1, k1);

    cout << "Case 1 - Deque: ";

    for(int x : ans1)
        cout << x << " ";

    cout << endl;


    vector<int> nums1_2 = {1, 3, -1, -3, 5, 3, 6, 7};

    vector<int> ans1_2 = maxSlidingWindowBrute(nums1_2, k1);

    cout << "Case 1 - Brute: ";

    for(int x : ans1_2)
        cout << x << " ";

    cout << endl;


    // ================= CASE 2 =================

    vector<int> nums2 = {1};
    int k2 = 1;

    vector<int> ans2 = maxSlidingWindow(nums2, k2);

    cout << "Case 2 - Deque: ";

    for(int x : ans2)
        cout << x << " ";

    cout << endl;


    return 0;
}