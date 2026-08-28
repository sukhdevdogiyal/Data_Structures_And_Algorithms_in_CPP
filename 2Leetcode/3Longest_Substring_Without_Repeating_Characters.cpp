// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// Method 1: Brute Force / Backward Checking
// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Method 2: Sliding Window + Hash
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// =====================================================
// METHOD 1: BRUTE FORCE / BACKWARD CHECKING
// =====================================================

int lengthOfLongestSubstring_BruteForce(string s) {

    int n = s.size();
    int ans = 0;
    int lower = -1;

    for (int i = 0; i < n; i++) {

        int j = i - 1;
        int count = 1;

        while (j > lower && s[i] != s[j]) {
            count++;
            j--;
        }

        if (j >= 0 && s[i] == s[j])
            lower = j;

        ans = max(ans, count);
    }

    return ans;
}


// =====================================================
// METHOD 2: SLIDING WINDOW + HASH
// =====================================================

int lengthOfLongestSubstring_SlidingWindow(string s) {

    int n = s.size();

    int left = 0;
    int right = 0;

    vector<int> hash(256, -1);

    int ans = 0;

    while (right < n) {

        if (hash[s[right]] != -1)
            left = max(left, hash[s[right]] + 1);

        int len = right - left + 1;

        ans = max(ans, len);

        hash[s[right]] = right;

        right++;
    }

    return ans;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    string s1 = "abcabcbb";

    cout << "CASE 1" << endl;
    cout << "String: " << s1 << endl;

    cout << "Method 1 (Brute Force): "
         << lengthOfLongestSubstring_BruteForce(s1) << endl;

    cout << "Method 2 (Sliding Window): "
         << lengthOfLongestSubstring_SlidingWindow(s1) << endl;


    cout << endl;


    // ================= CASE 2 =================

    string s2 = "bbbbb";

    cout << "CASE 2" << endl;
    cout << "String: " << s2 << endl;

    cout << "Method 1 (Brute Force): "
         << lengthOfLongestSubstring_BruteForce(s2) << endl;

    cout << "Method 2 (Sliding Window): "
         << lengthOfLongestSubstring_SlidingWindow(s2) << endl;


    cout << endl;


    // ================= CASE 3 =================

    string s3 = "pwwkew";

    cout << "CASE 3" << endl;
    cout << "String: " << s3 << endl;

    cout << "Method 1 (Brute Force): "
         << lengthOfLongestSubstring_BruteForce(s3) << endl;

    cout << "Method 2 (Sliding Window): "
         << lengthOfLongestSubstring_SlidingWindow(s3) << endl;


    cout << endl;


    // ================= CASE 4 =================

    string s4 = "";

    cout << "CASE 4" << endl;
    cout << "String: " << s4 << endl;

    cout << "Method 1 (Brute Force): "
         << lengthOfLongestSubstring_BruteForce(s4) << endl;

    cout << "Method 2 (Sliding Window): "
         << lengthOfLongestSubstring_SlidingWindow(s4) << endl;


    return 0;
}
