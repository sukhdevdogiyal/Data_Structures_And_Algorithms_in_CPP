// B. Impost or Sus
#include<iostream>
#include<stack>
using namespace std;
void cheak(string str)
{
    int n= str.length();
    int ans=0;
    if(str[0]=='u')
    {
        ans++;
        str[0]='s';
    }
    if(str[n-1]=='u')
    {
        ans++;
        str[n-1]='s';
    }
    for(int i=1;i<n-1;i++)
    {
        char ch = str[i];
        if (ch=='u'&&str[i-1]!='s')
        {
            ans++;
            str[i]='s';
        }
        
    }
    cout<<ans<<endl;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    while (n--)
    {
        string str;
        cin>>str;
        cheak(str);
    }
    
    return 0;
}

/*
input :-
9
sus
uuuu
sssss
uusuuu
suuuuuu
usssssss
sssuuusss
susuusuuus
uuuuuuuuuuu


output :-
0
3
0
3
3
1
1
2
6
*/