// 367. Valid Perfect Square
// https://leetcode.com/problems/valid-perfect-square/description/
#include <iostream>
using namespace std;

bool isPerfectSquare(int num) {
    if (num < 2)
        return true;

    int left = 1;
    int right = num / 2;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        long long square = (long long)mid * mid;

        if (square == num)
            return true;
        else if (square < num)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main() {

    // Test Case 1
    int num1 = 16;
    cout << "Test Case 1: "
         << (isPerfectSquare(num1) ? "true" : "false") << endl;

    // Test Case 2
    int num2 = 14;
    cout << "Test Case 2: "
         << (isPerfectSquare(num2) ? "true" : "false") << endl;

    // Test Case 3
    int num3 = 1;
    cout << "Test Case 3: "
         << (isPerfectSquare(num3) ? "true" : "false") << endl;

    return 0;
}
