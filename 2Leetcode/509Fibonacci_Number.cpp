// 509. Fibonacci Number

// https://leetcode.com/problems/fibonacci-number/


// Method 1: Simple Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(n)


// Method 2: Top-Down DP (Memoization)
// Time Complexity: O(n)
// Space Complexity: O(n)


// Method 3: Bottom-Up DP (Tabulation)
// Time Complexity: O(n)
// Space Complexity: O(n)


// Method 4: Space Optimized DP
// Time Complexity: O(n)
// Space Complexity: O(1)


// Method 5: Matrix Exponentiation
// Time Complexity: O(log n)
// Space Complexity: O(log n)


// Method 6: Fast Doubling
// Time Complexity: O(log n)
// Space Complexity: O(log n)


#include <iostream>
#include <vector>

using namespace std;


// =====================================================
// METHOD 1: SIMPLE RECURSION
// =====================================================

int fibRecursive(int n) {

    if(n == 0 || n == 1)
        return n;

    return fibRecursive(n - 1)
         + fibRecursive(n - 2);
}


// =====================================================
// METHOD 2: TOP-DOWN DP (MEMOIZATION)
// =====================================================

int solveMemo(int n, vector<int>& dp) {

    if(n == 0 || n == 1)
        return n;


    if(dp[n] != -1)
        return dp[n];


    dp[n] =
        solveMemo(n - 1, dp)
        +
        solveMemo(n - 2, dp);


    return dp[n];
}


int fibMemo(int n) {

    vector<int> dp(n + 1, -1);

    return solveMemo(n, dp);
}


// =====================================================
// METHOD 3: BOTTOM-UP DP (TABULATION)
// =====================================================

int fibTabulation(int n) {

    if(n == 0 || n == 1)
        return n;


    vector<int> dp(n + 1, 0);

    dp[0] = 0;
    dp[1] = 1;


    for(int i = 2; i <= n; i++) {

        dp[i] =
            dp[i - 1]
            +
            dp[i - 2];
    }


    return dp[n];
}


// =====================================================
// METHOD 4: SPACE OPTIMIZED DP
// =====================================================

int fibSpaceOptimized(int n) {

    if(n == 0 || n == 1)
        return n;


    int prev2 = 0;
    int prev1 = 1;


    for(int i = 2; i <= n; i++) {

        int curr = prev1 + prev2;

        prev2 = prev1;
        prev1 = curr;
    }


    return prev1;
}


// =====================================================
// METHOD 5: MATRIX EXPONENTIATION
// =====================================================

struct Matrix {

    long long a;
    long long b;
    long long c;
    long long d;
};


// Matrix Multiplication

Matrix multiply(Matrix x, Matrix y) {

    Matrix result;

    result.a =
        x.a * y.a +
        x.b * y.c;

    result.b =
        x.a * y.b +
        x.b * y.d;

    result.c =
        x.c * y.a +
        x.d * y.c;

    result.d =
        x.c * y.b +
        x.d * y.d;


    return result;
}


// Matrix Power

Matrix matrixPower(Matrix base, int n) {

    Matrix result = {1, 0, 0, 1};


    while(n > 0) {

        if(n % 2 == 1) {
            result = multiply(result, base);
        }

        base = multiply(base, base);

        n = n / 2;
    }


    return result;
}


int fibMatrix(int n) {

    if(n == 0)
        return 0;


    Matrix base = {
        1, 1,
        1, 0
    };


    Matrix result = matrixPower(base, n - 1);


    return result.a;
}


// =====================================================
// METHOD 6: FAST DOUBLING
// =====================================================

// Returns:
// {F(n), F(n+1)}

pair<long long, long long> fastDoubling(int n) {

    if(n == 0)
        return {0, 1};


    pair<long long, long long> half =
        fastDoubling(n / 2);


    long long a = half.first;
    long long b = half.second;


    // F(2k)
    long long c =
        a * (2 * b - a);


    // F(2k + 1)
    long long d =
        a * a + b * b;


    if(n % 2 == 0)
        return {c, d};


    return {d, c + d};
}


int fibFastDoubling(int n) {

    return fastDoubling(n).first;
}


// =====================================================
// MAIN
// =====================================================

int main() {


    // ================= CASE 1 =================

    int n1 = 5;


    cout << "Case 1 - Method 1: "
         << fibRecursive(n1)
         << endl;

    cout << "Case 1 - Method 2: "
         << fibMemo(n1)
         << endl;

    cout << "Case 1 - Method 3: "
         << fibTabulation(n1)
         << endl;

    cout << "Case 1 - Method 4: "
         << fibSpaceOptimized(n1)
         << endl;

    cout << "Case 1 - Method 5: "
         << fibMatrix(n1)
         << endl;

    cout << "Case 1 - Method 6: "
         << fibFastDoubling(n1)
         << endl << endl;



    // ================= CASE 2 =================

    int n2 = 10;


    cout << "Case 2 - Method 1: "
         << fibRecursive(n2)
         << endl;

    cout << "Case 2 - Method 2: "
         << fibMemo(n2)
         << endl;

    cout << "Case 2 - Method 3: "
         << fibTabulation(n2)
         << endl;

    cout << "Case 2 - Method 4: "
         << fibSpaceOptimized(n2)
         << endl;

    cout << "Case 2 - Method 5: "
         << fibMatrix(n2)
         << endl;

    cout << "Case 2 - Method 6: "
         << fibFastDoubling(n2)
         << endl << endl;



    // ================= CASE 3 =================

    int n3 = 0;


    cout << "Case 3 - Method 1: "
         << fibRecursive(n3)
         << endl;

    cout << "Case 3 - Method 2: "
         << fibMemo(n3)
         << endl;

    cout << "Case 3 - Method 3: "
         << fibTabulation(n3)
         << endl;

    cout << "Case 3 - Method 4: "
         << fibSpaceOptimized(n3)
         << endl;

    cout << "Case 3 - Method 5: "
         << fibMatrix(n3)
         << endl;

    cout << "Case 3 - Method 6: "
         << fibFastDoubling(n3)
         << endl;


    return 0;
}