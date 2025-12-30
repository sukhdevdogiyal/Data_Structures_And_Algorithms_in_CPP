// A. Yes or Yes
#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        int i = 0;
        int count = 0;
        while (i < str.length())
        {
            if (str[i] == 'Y')
            {
                count++;
            }
            if (count == 2)
                break;
            i++;
        }
        if (count <= 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
/*
input:-
7
YY
NN
NNY
YYYNY
NNNNN
YYYYYY
YNNNNN

output:-
NO
YES
YES
NO
YES
NO
YES

*/