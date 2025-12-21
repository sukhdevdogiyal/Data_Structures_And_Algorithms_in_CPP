#include <iostream>
using namespace std;
bool scoreBalance(string s)
{
    int f = 0;
    int l = 0;
    int total = 0;
    for (int i = 0; i < s.size(); i++)
    {
        total = total + (s[i] - 'a') + 1;
        // cout<<s[i]-'a'+1<<" "<<total<<endl;
    }
    // cout<<total<<endl;
    for (int i = 0; i < s.size() - 1; i++)
    {
        f = f + ((int)s[i] - 'a' + 1);
        l = total - f;
        // cout<<f<<" "<<l<<endl;
        if (f == l)
        {
            return true;
        }
        if (f > l)
        {
            return false;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    // cout << scoreBalance("adcb");
    // cout << scoreBalance("ac");
    // cout << scoreBalance("bace");
     cout << scoreBalance("ss");
    return 0;
}
