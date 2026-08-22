// 28. Find the Index of the First Occurrence in a String
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

// Method 1: Using find()
// Time Complexity: O(n * m) - implementation dependent
// Space Complexity: O(1) - implementation dependent

// Method 2: Brute Force
// Time Complexity: O(n * m)
// Space Complexity: O(1)

#include <iostream>
#include <string>
using namespace std;


// =====================================================
// METHOD 1: USING find()
// =====================================================

int strStr_Find(string haystack, string needle) {
    return haystack.find(needle);
}


// =====================================================
// METHOD 2: BRUTE FORCE
// =====================================================

int strStr_BruteForce(string haystack, string needle) {

    int n = haystack.size();
    int m = needle.size();

    if (m == 0)
        return 0;

    for (int i = 0; i <= n - m; i++) {

        int j = 0;

        while (j < m && haystack[i + j] == needle[j]) {
            j++;
        }

        if (j == m)
            return i;
    }

    return -1;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    string haystack1 = "sadbutsad";
    string needle1 = "sad";

    cout << "CASE 1" << endl;
    cout << "Haystack: " << haystack1 << endl;
    cout << "Needle: " << needle1 << endl;

    cout << "Method 1 (find): "
         << strStr_Find(haystack1, needle1) << endl;

    cout << "Method 2 (Brute Force): "
         << strStr_BruteForce(haystack1, needle1) << endl;


    cout << endl;


    // ================= CASE 2 =================

    string haystack2 = "leetcode";
    string needle2 = "leeto";

    cout << "CASE 2" << endl;
    cout << "Haystack: " << haystack2 << endl;
    cout << "Needle: " << needle2 << endl;

    cout << "Method 1 (find): "
         << strStr_Find(haystack2, needle2) << endl;

    cout << "Method 2 (Brute Force): "
         << strStr_BruteForce(haystack2, needle2) << endl;


    cout << endl;


    // ================= CASE 3 =================

    string haystack3 = "hello";
    string needle3 = "ll";

    cout << "CASE 3" << endl;
    cout << "Haystack: " << haystack3 << endl;
    cout << "Needle: " << needle3 << endl;

    cout << "Method 1 (find): "
         << strStr_Find(haystack3, needle3) << endl;

    cout << "Method 2 (Brute Force): "
         << strStr_BruteForce(haystack3, needle3) << endl;


    return 0;
}
