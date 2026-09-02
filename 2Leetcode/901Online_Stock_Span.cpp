// 901. Online Stock Span

// https://leetcode.com/problems/online-stock-span/description/

// Method 1: Brute Force
// Time Complexity: O(n) per next() call
// Space Complexity: O(n)

// Method 2: Monotonic Stack
// Time Complexity: O(1) amortized per next() call
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// =====================================================
// METHOD 1: BRUTE FORCE
// =====================================================

class StockSpanner_BruteForce
{

    vector<int> stock;

public:
    StockSpanner_BruteForce()
    {
    }

    int next(int price)
    {

        stock.push_back(price);

        int i = stock.size() - 1;

        int ans = 0;

        while (i >= 0 && stock[i] <= price)
        {

            ans++;
            i--;
        }

        return ans;
    }
};

// =====================================================
// METHOD 2: MONOTONIC STACK
// =====================================================

class StockSpanner_Stack
{

    // pair = {price, span}
    stack<pair<int, int>> st;

public:
    StockSpanner_Stack()
    {
    }

    int next(int price)
    {

        int ans = 1;

        while (!st.empty() && st.top().first <= price)
        {
            ans += st.top().second;
            st.pop();
        }

        st.push({price, ans});

        return ans;
    }
};

// =====================================================
// MAIN
// =====================================================

int main()
{

    // ================= CASE 1 =================

    vector<int> prices1 = {
        100, 80, 60, 70, 60, 75, 85};

    cout << "CASE 1" << endl;

    StockSpanner_BruteForce obj1;
    StockSpanner_Stack obj2;

    cout << "Prices: ";

    for (int price : prices1)
        cout << price << " ";

    cout << endl;

    cout << "Method 1 (Brute Force): ";

    for (int price : prices1)
        cout << obj1.next(price) << " ";

    cout << endl;

    cout << "Method 2 (Monotonic Stack): ";

    for (int price : prices1)
        cout << obj2.next(price) << " ";

    cout << endl
         << endl;

    // ================= CASE 2 =================

    vector<int> prices2 = {
        10, 20, 30, 40, 50};

    cout << "CASE 2" << endl;

    StockSpanner_BruteForce obj3;
    StockSpanner_Stack obj4;

    cout << "Prices: ";

    for (int price : prices2)
        cout << price << " ";

    cout << endl;

    cout << "Method 1 (Brute Force): ";

    for (int price : prices2)
        cout << obj3.next(price) << " ";

    cout << endl;

    cout << "Method 2 (Monotonic Stack): ";

    for (int price : prices2)
        cout << obj4.next(price) << " ";

    cout << endl
         << endl;

    // ================= CASE 3 =================

    vector<int> prices3 = {
        50, 40, 30, 20, 10};

    cout << "CASE 3" << endl;

    StockSpanner_BruteForce obj5;
    StockSpanner_Stack obj6;

    cout << "Prices: ";

    for (int price : prices3)
        cout << price << " ";

    cout << endl;

    cout << "Method 1 (Brute Force): ";

    for (int price : prices3)
        cout << obj5.next(price) << " ";

    cout << endl;

    cout << "Method 2 (Monotonic Stack): ";

    for (int price : prices3)
        cout << obj6.next(price) << " ";

    cout << endl
         << endl;

    // ================= CASE 4 =================

    vector<int> prices4 = {
        100, 100, 100, 100};

    cout << "CASE 4" << endl;

    StockSpanner_BruteForce obj7;
    StockSpanner_Stack obj8;

    cout << "Prices: ";

    for (int price : prices4)
        cout << price << " ";

    cout << endl;

    cout << "Method 1 (Brute Force): ";

    for (int price : prices4)
        cout << obj7.next(price) << " ";

    cout << endl;

    cout << "Method 2 (Monotonic Stack): ";

    for (int price : prices4)
        cout << obj8.next(price) << " ";

    cout << endl;

    return 0;
}