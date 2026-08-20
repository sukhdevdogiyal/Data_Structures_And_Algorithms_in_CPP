// 744. Find Smallest Letter Greater Than Target
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
#include <iostream>
#include <vector>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
    int n = letters.size();
    int left = 0;
    int right = n-1;
    int ans = n;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(letters[mid]==target)
        {
            left = mid+1;
        }
        else if(letters[mid]>target)
        {
            ans = mid;
            right = mid-1;
        }
        else
            left = mid+1;
    }
    if(ans == n)
        return letters[0];
    return letters[ans];
}

int main() {
    // Test Case 1
    vector<char> letters1 = {'c', 'f', 'j'};
    char target1 = 'a';
    cout << "Test Case 1: " << nextGreatestLetter(letters1, target1) << endl;

    // Test Case 2
    vector<char> letters2 = {'c', 'f', 'j'};
    char target2 = 'c';
    cout << "Test Case 2: " << nextGreatestLetter(letters2, target2) << endl;

    // Test Case 3
    vector<char> letters3 = {'c', 'f', 'j'};
    char target3 = 'j';
    cout << "Test Case 3: " << nextGreatestLetter(letters3, target3) << endl;

    return 0;
}
