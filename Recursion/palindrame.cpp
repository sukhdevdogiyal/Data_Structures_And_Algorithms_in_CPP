#include<iostream>
using namespace std;
bool reverse(string &rev,int i,int n)
{
    if (i>n-i-1)
    {
        return true;
    }
    if(rev[i]!=rev[n-i-1])
    {
        return false;
    }
    else
     reverse(rev,i+1,n);

    
}
int main(int argc, char const *argv[])
{
    string st="AabccbaA";
    string rev=st;
    int n =st.length();
    if (reverse(rev,0,n))
    {
        cout<<"string is palindrame";
    }
    else
    cout<<"string is not paildrame";
    
    return 0;
}
