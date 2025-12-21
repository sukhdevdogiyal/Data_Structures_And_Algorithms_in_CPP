#include<iostream>
#include<string>
#include<vector>
using namespace std;
void subsequence(string str,int index,string output,vector<string>&ans)
{
    // Base case
    if (index>=str.length())
    {
        if (output.length()!=0)
        {
            ans.push_back(output);
        }
        
        return;
    }
    // exqude
    subsequence(str,index+1,output,ans);
    // include
    char ch=str[index];
    output.push_back(ch);
    subsequence(str,index+1,output,ans);
    
}
int main()
{
    string str = "abc";
    //str.push_back('f');
    cout<<"Code360 :- Subsequence "<<endl;
    cout<<"Input string :  ";
    cout<<str<<endl;
    string output;
    vector<string>ans;
    subsequence(str,0,output,ans);
    cout<<"Total Subsequence : ";
    int a=str.length();
    cout<<(1<<a)-1;//it is a 2 ki power a
    cout<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        
        cout<<i+1<<". "<<ans[i];
        cout<<endl;
        
    }
    return 0;
}
