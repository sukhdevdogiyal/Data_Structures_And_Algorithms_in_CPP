#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    int n;
    int x, y;
    bool ch;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        ch = false;
        for (int i = 0; i < n-1; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                int m = arr[j] % arr[i];
                //cout<<"mod = "<<m<<endl;
                if (m % 2 == 0&&m>0)
                {
                    x = arr[i];
                    y = arr[j];
                    ch = true;
                    break;
                }
            }
            if (ch)
            {
                cout << x << " " << y << endl;
                break;
            }
        }
        if (!ch)
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}
/*
input :-
4
5
1 3 4 5 6
6
2 3 5 7 11 13
4
2 3 13 37
3
17 117 1117

*/