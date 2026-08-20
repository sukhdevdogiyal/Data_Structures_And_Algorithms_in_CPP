// Riptide
// https://codeforces.com/contest/2254/problem/A
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int ans = 0;

        while (true)
        {
            if (a == b || b == c || a == c)
                break;

            int mx = max(a, max(b, c));
            int mn = min(a, min(b, c));

            if (a == mx)
                a--;
            else if (b == mx)
                b--;
            else
                c--;

            if (a == mn)
                a++;
            else if (b == mn)
                b++;
            else
                c++;

            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
