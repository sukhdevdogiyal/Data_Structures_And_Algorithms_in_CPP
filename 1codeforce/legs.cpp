// Problem:	1996A - Legs
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int>a={3,33};
    cout<<a.back();
    int cas;
    cin >> cas;
    vector<int> v;
    
    for (int i = 0; i < cas; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < cas; i++)
    {
        int n = v[i];
        if (n % 2 == 1)
        {
            break;
        }

        int cow = 0;
        int hen = 0;
        if (n >= 4)
        {

            cow = n / 4;
            n = n % 4;
        }
        if (n >= 2)
        {
            hen = n / 2;
            n = n % 2;
        }
        cout << (cow + hen) << endl;
    }
    return 0;
}