#include <iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> ch(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ch[i];
    }
    for (int i = 0; i < n; i++)
    {
        int c=ch[i];
        int rem = c % 3;
        int ans = 3 - rem;
        if (ans == 3)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << ans<<endl;
        }
    }

    return 0;
}
