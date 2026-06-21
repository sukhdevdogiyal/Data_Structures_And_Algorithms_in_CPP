#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int solve(int n, int x, int y, int z, vector<int>& dp)
{
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MIN;

    if (dp[n] != INT_MIN)
        return dp[n];

    int a = solve(n - x, x, y, z, dp);
    int b = solve(n - y, x, y, z, dp);
    int c = solve(n - z, x, y, z, dp);

    return dp[n] = max(a, max(b, c)) + 1;
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN);

    int ans = solve(n, x, y, z, dp);

    return (ans < 0) ? 0 : ans;
}

int main()
{
    // Test Case 1
    cout << "Test Case 1:" << endl;
    cout << "n = 7, x = 5, y = 2, z = 2" << endl;
    cout << "Maximum number of cuts = "
         << maximizeTheCuts(7, 5, 2, 2) << endl;

    // Test Case 2
    cout << "\nTest Case 2:" << endl;
    cout << "n = 4, x = 2, y = 1, z = 1" << endl;
    cout << "Maximum number of cuts = "
         << maximizeTheCuts(4, 2, 1, 1) << endl;

    // Test Case 3
    cout << "\nTest Case 3:" << endl;
    cout << "n = 5, x = 4, y = 2, z = 6" << endl;
    cout << "Maximum number of cuts = "
         << maximizeTheCuts(5, 4, 2, 6) << endl;

    return 0;
}
