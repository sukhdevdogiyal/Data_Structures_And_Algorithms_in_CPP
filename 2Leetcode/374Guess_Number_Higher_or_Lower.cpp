// 374. Guess Number Higher or Lower
// https://leetcode.com/problems/guess-number-higher-or-lower/description/

#include <iostream>
using namespace std;

// Simulated guess API
int pickedNumber;

int guess(int num) {
    if (num > pickedNumber)
        return -1;
    else if (num < pickedNumber)
        return 1;
    else
        return 0;
}

int guessNumber(int n) {
    int low = 1;
    int high = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int ans = guess(mid);

        if (ans == 0)
            return mid;
        else if (ans == -1)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main() {

    // Test Case 1
    pickedNumber = 6;
    cout << "Test Case 1: " << guessNumber(10) << endl;

    // Test Case 2
    pickedNumber = 1;
    cout << "Test Case 2: " << guessNumber(10) << endl;

    // Test Case 3
    pickedNumber = 15;
    cout << "Test Case 3: " << guessNumber(20) << endl;

    return 0;
}
