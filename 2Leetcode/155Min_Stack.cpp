// 155. Min Stack
// https://leetcode.com/problems/min-stack/description/

// Method 1: Two Stacks
// Time Complexity: O(1) for push, pop, top, getMin
// Space Complexity: O(n)

// Method 2: Single Stack + Encoding
// Time Complexity: O(1) for push, pop, top, getMin
// Space Complexity: O(n)

#include <iostream>
#include <stack>

using namespace std;

// =====================================================
// METHOD 1: TWO STACKS
// =====================================================

class MinStack_TwoStacks {
    stack<long long> s;
    stack<long long> minStack;

public:

    void push(int val) {
        s.push(val);

        if (minStack.empty())
            minStack.push(val);
        else
            minStack.push(min((long long)val, minStack.top()));
    }

    void pop() {
        if (s.empty())
            return;

        s.pop();
        minStack.pop();
    }

    int top() {
        if (s.empty())
            return -1;

        return (int)s.top();
    }

    int getMin() {
        if (minStack.empty())
            return -1;

        return (int)minStack.top();
    }
};


// =====================================================
// METHOD 2: SINGLE STACK + ENCODING
// =====================================================

class MinStack_Encoding {
    long long minVal;
    stack<long long> s;

public:

    MinStack_Encoding() {
        minVal = 0;
    }

    void push(int val) {

        if (s.empty()) {
            s.push(val);
            minVal = val;
        }
        else if (val < minVal) {

            // Encode the previous minimum
            s.push(2LL * val - minVal);

            // Update minimum
            minVal = val;
        }
        else {
            s.push(val);
        }
    }

    void pop() {

        if (s.empty())
            return;

        long long curr = s.top();
        s.pop();

        // Encoded value means current minimum
        // was changed during push
        if (curr < minVal) {

            // Recover previous minimum
            minVal = 2LL * minVal - curr;
        }
    }

    int top() {

        if (s.empty())
            return -1;

        long long curr = s.top();

        // Encoded value
        if (curr < minVal)
            return (int)minVal;

        return (int)curr;
    }

    int getMin() {

        if (s.empty())
            return -1;

        return (int)minVal;
    }
};


// =====================================================
// MAIN
// =====================================================

int main() {

    // ================= CASE 1 =================

    cout << "CASE 1" << endl;

    MinStack_Encoding s1;

    s1.push(-2);
    s1.push(0);
    s1.push(-3);

    cout << "Get Min: " << s1.getMin() << endl;

    s1.pop();
    cout<<"Pop()"<<endl;

    cout << "Top: " << s1.top() << endl;
    cout << "Get Min: " << s1.getMin() << endl;


    cout << endl;


    // ================= CASE 2 =================

    cout << "CASE 2" << endl;

    MinStack_Encoding s2;

    s2.push(5);
    s2.push(3);
    s2.push(7);
    s2.push(2);
    s2.push(4);

    cout << "Top: " << s2.top() << endl;
    cout << "Get Min: " << s2.getMin() << endl;

    s2.pop();
    cout<<"Pop()"<<endl;

    cout << "After Pop:" << endl;
    cout << "Top: " << s2.top() << endl;
    cout << "Get Min: " << s2.getMin() << endl;

    s2.pop();
    cout<<"Pop()"<<endl;

    cout << "After Pop:" << endl;
    cout << "Top: " << s2.top() << endl;
    cout << "Get Min: " << s2.getMin() << endl;


    cout << endl;


    // ================= CASE 3 =================

    cout << "CASE 3" << endl;

    MinStack_Encoding s3;

    s3.push(10);
    s3.push(5);
    s3.push(1);
    s3.push(-2);

    cout << "Get Min: " << s3.getMin() << endl;

    s3.pop();
    cout<<"Pop()"<<endl;
    
    cout << "After Pop:" << endl;
    cout << "Top: " << s3.top() << endl;
    cout << "Get Min: " << s3.getMin() << endl;
    
    s3.pop();
    cout<<"Pop()"<<endl;

    cout << "After Pop:" << endl;
    cout << "Top: " << s3.top() << endl;
    cout << "Get Min: " << s3.getMin() << endl;


    return 0;
}


