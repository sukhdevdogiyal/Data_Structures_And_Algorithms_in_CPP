// 1461. Check If a String Contains All Binary Codes of Size K
// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/?envType=daily-question&envId=2026-02-23
// Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
void allcomb(int k,int i,vector<string>&comb,string op)
{
    if(i==k)
    {
        comb.push_back(op);
        return;
    }
    op.push_back('0');
    allcomb(k,i+1,comb,op);
    op.pop_back();
    op.push_back('1');
    allcomb(k,i+1,comb,op);
}
bool hasAllCodes(string s, int k)
{
    vector<string> comb;
    string op = "";
    allcomb(k,0,comb,op);
    unordered_map<string,bool>m;
    for(int i=0;i<comb.size();i++)
    {
        m[comb[i]]=false;
    }
    for(int i = 0;i<=s.size()-k;i++)
    {
        string ch ="";
        for (int j = i; j < i+k; j++)
        {
            ch.push_back(s[j]);
        }
        m[ch]=true;
    }
    for(auto i:m)
    {
        if (i.second==false)
        {
            return false;
        }
        
    }
    return true; 
}
int main(int argc, char const *argv[])
{
    string s = "00110110";
    s="0";
    int k = 1;
    cout<<"String s = "<<s<<"\tk = "<<k<<endl;
    //hasAllCodes(s,k);
    cout<<"All Code in String : "<<hasAllCodes(s,k);
    return 0;
}
