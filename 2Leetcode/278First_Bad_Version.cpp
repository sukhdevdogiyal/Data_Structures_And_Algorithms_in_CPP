// 278. First Bad Version
// https://leetcode.com/problems/first-bad-version/description/

#include <iostream>
using namespace std;

// Simulated API
int badVersion;

bool isBadVersion(int version) {
    return version >= badVersion;
}

int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isBadVersion(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}

int main() {

    // Test Case 1
    badVersion = 4;
    cout << "Test Case 1: "
         << firstBadVersion(5) << endl;

    // Test Case 2
    badVersion = 1;
    cout << "Test Case 2: "
         << firstBadVersion(10) << endl;

    // Test Case 3
    badVersion = 7;
    cout << "Test Case 3: "
         << firstBadVersion(10) << endl;

    return 0;
}
