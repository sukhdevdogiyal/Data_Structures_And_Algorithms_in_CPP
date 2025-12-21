#include <iostream>
#include <string.h>
using namespace std;
int getlength(string s)
{

    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        count++;
    }
    //cout << "count = " << count << endl;
    return count;
}
char tolowercase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {

        return ch;
    }
    else if (ch >= '0' && ch <= '9')
    {
        //cout << "CH = " << ch;
        return ch;
    }
    else
    {
        return ch - 'A' + 'a';
    }
}
bool checkPalindrome(string s)
{
    int n = getlength(s);
    int f = 0;
    int l = n - 1;
    while (f <= l)
    {
        if (tolowercase(s[f]) < '0' || (tolowercase(s[f]) > '9' && tolowercase(s[f]) < 'a') || tolowercase(s[f]) > 'z')
        {
            //cout << "s[f] = " << s[f] << endl;
            f++;
        }
        else if (tolowercase(s[l]) < '0' || (tolowercase(s[l]) > '9' && tolowercase(s[l]) < 'a') || tolowercase(s[l]) > 'z')
        {
            //cout << "s[l] = " << s[l] << endl;
            l--;
        }
        else if (tolowercase(s[f]) != tolowercase(s[l]))
        {
            return false;
        }
        else
        {
            f++;
            l--;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cout << "\npalindrome = " << checkPalindrome("c1 O$d@eeD o1c");
    return 0;
}
