// 2073. Time Needed to Buy Tickets

// https://leetcode.com/problems/time-needed-to-buy-tickets/

// Method 1: Counting
// Time Complexity: O(n)
// Space Complexity: O(1)

// Method 2: Queue Simulation
// Time Complexity: O(total tickets)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// =====================================================
// METHOD 1: COUNTING
// =====================================================

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        int time = 0;
        int n = tickets.size();

        for(int i = 0; i < n; i++) {

            if(tickets[i] < tickets[k]) {
                time += tickets[i];
            }
            else if(i <= k) {
                time += tickets[k];
            }
            else {
                time += tickets[k] - 1;
            }
        }

        return time;
    }
};


// =====================================================
// METHOD 2: QUEUE SIMULATION
// =====================================================

class Solution2 {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        queue<int> q;

        // Queue mein person ke indices store karenge
        for(int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }

        int time = 0;

        while(!q.empty()) {

            // Front person
            int person = q.front();
            q.pop();

            // Ek ticket kharidi
            tickets[person]--;
            time++;

            // Agar k person ka last ticket tha
            if(person == k && tickets[person] == 0) {
                return time;
            }

            // Agar is person ke tickets abhi remaining hain
            if(tickets[person] > 0) {
                q.push(person);
            }
        }

        return time;
    }
};


// =====================================================
// MAIN
// =====================================================

int main() {

    Solution obj1;
    Solution2 obj2;

    // ================= CASE 1 =================

    vector<int> tickets1 = {2, 3, 2};
    int k1 = 2;

    cout << "Case 1 - Counting: "
         << obj1.timeRequiredToBuy(tickets1, k1)
         << endl;

    vector<int> tickets1_2 = {2, 3, 2};

    cout << "Case 1 - Queue: "
         << obj2.timeRequiredToBuy(tickets1_2, k1)
         << endl;


    // ================= CASE 2 =================

    vector<int> tickets2 = {5, 1, 1, 1};
    int k2 = 0;

    cout << "Case 2 - Counting: "
         << obj1.timeRequiredToBuy(tickets2, k2)
         << endl;

    vector<int> tickets2_2 = {5, 1, 1, 1};

    cout << "Case 2 - Queue: "
         << obj2.timeRequiredToBuy(tickets2_2, k2)
         << endl;


    return 0;
}