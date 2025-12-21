// #include <iostream>
// using namespace std;
// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;
//     while (n)
//     {
//         int m;
//         cin >> m;
//         int ans = 0;
//         while (m >= 3)
//         {
//             int t=m;
//             m = m / 3;
//             ans = ans + m;
//             if (t % 3 != 0)
//             {
//                 m++;
//             }
//         }
//         cout<<ans<<endl;

//         n--;
//     }

//     return 0;
// }
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // number of test cases
    while (t--) {
        long long n;
        cin >> n;
        long long ans = n / 3;
        if (n % 3 == 2)
            ans++;
        cout << ans << "\n";
    }
    return 0;
}
