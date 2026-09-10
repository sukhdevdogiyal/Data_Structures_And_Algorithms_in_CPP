// 933. Number of Recent Calls

// https://leetcode.com/problems/number-of-recent-calls/description/

// Method 1: Queue
// Time Complexity: O(n) amortized
// Space Complexity: O(n)

#include <iostream>
#include <queue>

using namespace std;

// =====================================================
// METHOD 1: QUEUE
// =====================================================

class RecentCounter {

    queue<int> request;

public:

    RecentCounter() {

    }

    int ping(int t) {

        request.push(t);

        while (!request.empty() &&
               request.front() < t - 3000) {

            request.pop();
        }

        return request.size();
    }
};


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    RecentCounter obj1;

    cout << "CASE 1" << endl;

    cout << "Ping(1): "
         << obj1.ping(1) << endl;

    cout << "Ping(100): "
         << obj1.ping(100) << endl;

    cout << "Ping(3001): "
         << obj1.ping(3001) << endl;

    cout << "Ping(3002): "
         << obj1.ping(3002) << endl;

    cout << endl;


    // ================= CASE 2 =================

    RecentCounter obj2;

    cout << "CASE 2" << endl;

    cout << "Ping(1): "
         << obj2.ping(1) << endl;

    cout << "Ping(3000): "
         << obj2.ping(3000) << endl;

    cout << "Ping(6000): "
         << obj2.ping(6000) << endl;

    cout << endl;


    // ================= CASE 3 =================

    RecentCounter obj3;

    cout << "CASE 3" << endl;

    cout << "Ping(10): "
         << obj3.ping(10) << endl;

    cout << "Ping(20): "
         << obj3.ping(20) << endl;

    cout << "Ping(30): "
         << obj3.ping(30) << endl;

    cout << "Ping(4000): "
         << obj3.ping(4000) << endl;


    return 0;
}