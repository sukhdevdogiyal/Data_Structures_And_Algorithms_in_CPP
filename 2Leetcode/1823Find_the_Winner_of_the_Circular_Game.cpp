// 1823. Find the Winner of the Circular Game

// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// Method 1: Queue Simulation
// Time Complexity: O(n * k)
// Space Complexity: O(n)

// Method 2: Josephus Formula
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <queue>

using namespace std;

// =====================================================
// METHOD 1: QUEUE SIMULATION
// =====================================================

int findTheWinner(int n, int k) {

    queue<int> q;

    // Add players 1 to n
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }

    int i = 0;

    while(q.size() != 1) {

        i++;

        // Current player is not eliminated
        // Move him to the back
        if(i < k) {
            q.push(q.front());
        }

        // After reaching k, reset counter
        if(i == k) {
            i = 0;
        }

        // Remove front player
        q.pop();
    }

    return q.front();
}


// =====================================================
// METHOD 2: JOSEPHUS FORMULA
// =====================================================

int findTheWinnerOptimized(int n, int k) {

    int ans = 0;

    // Start with 0 for one player
    for(int i = 2; i <= n; i++) {

        ans = (ans + k) % i;
    }

    // Convert 0-based index to 1-based player
    return ans + 1;
}


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    int n1 = 5;
    int k1 = 2;

    cout << "Case 1 - Queue: "
         << findTheWinner(n1, k1)
         << endl;

    cout << "Case 1 - Formula: "
         << findTheWinnerOptimized(n1, k1)
         << endl;


    // ================= CASE 2 =================

    int n2 = 6;
    int k2 = 5;

    cout << "Case 2 - Queue: "
         << findTheWinner(n2, k2)
         << endl;

    cout << "Case 2 - Formula: "
         << findTheWinnerOptimized(n2, k2)
         << endl;


    // ================= CASE 3 =================

    int n3 = 1;
    int k3 = 1;

    cout << "Case 3 - Queue: "
         << findTheWinner(n3, k3)
         << endl;

    cout << "Case 3 - Formula: "
         << findTheWinnerOptimized(n3, k3)
         << endl;


    return 0;
}