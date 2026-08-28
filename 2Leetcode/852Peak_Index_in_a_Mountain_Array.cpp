// 852. Peak Index in a Mountain Array

// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

// Method 1: Linear Search
// Time Complexity: O(n)
// Space Complexity: O(1)

// Method 2: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>

using namespace std;

// =====================================================
// METHOD 1: LINEAR SEARCH
// =====================================================

int peakIndexInMountainArray_Linear(vector<int>& arr) {

    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {

        if (arr[i] > arr[i + 1])
            return i;
    }

    return -1;
}


// =====================================================
// METHOD 2: BINARY SEARCH
// =====================================================

int peakIndexInMountainArray_Binary(vector<int>& arr) {

    int s = 0;
    int e = arr.size() - 1;

    while (s < e) {

        int mid = s + (e - s) / 2;

        if (arr[mid] > arr[mid + 1]) {

            // We are on decreasing side
            // Peak can be mid or before mid
            e = mid;
        }
        else {

            // We are on increasing side
            // Peak is after mid
            s = mid + 1;
        }
    }

    return s;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    vector<int> arr1 = {0, 2, 1, 0};

    cout << "CASE 1" << endl;
    cout << "Array: ";

    for (int x : arr1)
        cout << x << " ";

    cout << endl;

    cout << "Method 1 (Linear Search): "
         << peakIndexInMountainArray_Linear(arr1) << endl;

    cout << "Method 2 (Binary Search): "
         << peakIndexInMountainArray_Binary(arr1) << endl;

    cout << endl;


    // ================= CASE 2 =================

    vector<int> arr2 = {0, 10, 5, 2};

    cout << "CASE 2" << endl;
    cout << "Array: ";

    for (int x : arr2)
        cout << x << " ";

    cout << endl;

    cout << "Method 1 (Linear Search): "
         << peakIndexInMountainArray_Linear(arr2) << endl;

    cout << "Method 2 (Binary Search): "
         << peakIndexInMountainArray_Binary(arr2) << endl;

    cout << endl;


    // ================= CASE 3 =================

    vector<int> arr3 = {1, 3, 7, 9, 6, 4, 2};

    cout << "CASE 3" << endl;
    cout << "Array: ";

    for (int x : arr3)
        cout << x << " ";

    cout << endl;

    cout << "Method 1 (Linear Search): "
         << peakIndexInMountainArray_Linear(arr3) << endl;

    cout << "Method 2 (Binary Search): "
         << peakIndexInMountainArray_Binary(arr3) << endl;

    cout << endl;


    // ================= CASE 4 =================

    vector<int> arr4 = {1, 2, 4, 8, 6, 3};

    cout << "CASE 4" << endl;
    cout << "Array: ";

    for (int x : arr4)
        cout << x << " ";

    cout << endl;

    cout << "Method 1 (Linear Search): "
         << peakIndexInMountainArray_Linear(arr4) << endl;

    cout << "Method 2 (Binary Search): "
         << peakIndexInMountainArray_Binary(arr4) << endl;


    return 0;
}