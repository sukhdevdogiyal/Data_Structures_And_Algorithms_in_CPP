// LeetCode 1700 - Number of Students Unable to Eat Lunch

// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

// Method 1: Count 0 and 1
// Time Complexity: O(n)
// Space Complexity: O(1)

// Method 2: Queue Simulation
// Time Complexity: O(n)
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
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        int count0 = 0;
        int count1 = 0;

        // Count students
        for(int i = 0; i < students.size(); i++) {
            if(students[i] == 0)
                count0++;
            else
                count1++;
        }

        // Process sandwiches
        for(int i = 0; i < sandwiches.size(); i++) {

            // Current sandwich = 0
            if(sandwiches[i] == 0) {

                // No student wants 0
                if(count0 == 0)
                    return students.size() - i;

                count0--;
            }

            // Current sandwich = 1
            else {

                // No student wants 1
                if(count1 == 0)
                    return students.size() - i;

                count1--;
            }
        }

        return 0;
    }
};


// =====================================================
// METHOD 2: QUEUE SIMULATION
// =====================================================

class Solution2 {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        queue<int> q;

        for(int student : students)
            q.push(student);

        int i = 0;
        int rotations = 0;

        while(!q.empty() && rotations < q.size()) {

            // Student wants current sandwich
            if(q.front() == sandwiches[i]) {

                q.pop();
                i++;
                rotations = 0;
            }

            // Student doesn't want it
            else {

                int student = q.front();
                q.pop();
                q.push(student);

                rotations++;
            }
        }

        return q.size();
    }
};


// =====================================================
// MAIN
// =====================================================

int main() {

    Solution obj;

    // ================= CASE 1 =================

    vector<int> students1 = {1, 1, 0, 0};
    vector<int> sandwiches1 = {0, 1, 0, 1};

    cout << "Case 1: "
         << obj.countStudents(students1, sandwiches1)
         << endl;


    // ================= CASE 2 =================

    vector<int> students2 = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches2 = {1, 0, 0, 0, 1, 1};

    cout << "Case 2: "
         << obj.countStudents(students2, sandwiches2)
         << endl;


    // ================= CASE 3 =================

    vector<int> students3 = {0, 0, 0};
    vector<int> sandwiches3 = {1, 1, 1};

    cout << "Case 3: "
         << obj.countStudents(students3, sandwiches3)
         << endl;


    return 0;
}