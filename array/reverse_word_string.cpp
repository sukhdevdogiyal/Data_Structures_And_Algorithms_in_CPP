#include<iostream>
//#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void reversr(string &s)
{
    int f=0;
    int l=s.length()-1;
    while (f<l)
    {
        swap(s[f++],s[l--]);
    }
}
void reverseworld(string &s)
{
    int f=0,l;
    int i=0;
    int n=s.length();
    while (i<=n)
    {
        if (s[i]==' '||s[i]=='\0')
        {
            l=i-1;
            while (f<l)
            {
                swap(s[f++],s[l--]);
            }
            f=i+1;
        }
        i++;
    }
    
}
int main(int argc, char const *argv[])
{
    //vector<char>s;
    string s = "the sky is blue";
    cout<<s;
    reversr(s);
    cout<<endl<<s;
    reverseworld(s);
    cout<<endl<<s;
    return 0;
}
