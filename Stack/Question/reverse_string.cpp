#include<iostream>
#include<stack>
using namespace std;
int main(int argc, char const *argv[])
{
    string str ="sukhdev";
    stack<char>s;
    int i=0;
    while (str[i]!='\0')
    {
        s.push(str[i]);
        i++;
    }
    string ans = "";
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    cout<<"Befor reverse string : "<<str<<endl;
    cout<<"After reverse string : "<<ans<<endl;
    
    
    return 0;
}
