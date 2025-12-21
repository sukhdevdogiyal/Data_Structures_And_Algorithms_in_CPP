// Sequence Game
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int x;
        cin >> x;
        int ch = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int min1 = min(a[i], a[i + 1]);
            int max1 = max(a[i], a[i + 1]);
            for (int j = min1 + 1; j < max1; j++)
            {
                if (j == x)
                {

                    ch = 1;
                    break;
                }
            }
        }
        if (ch == 1)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}
// worng answer