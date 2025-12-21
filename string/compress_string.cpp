#include <iostream>
#include <vector>
#include<string>
using namespace std;
void push_count(vector<char>&v,int n)
{
    vector<char>t;
    while(n!=0)
    {
        int r = n%10;
        t.push_back(r+'0');
        n=n/10;
    }
    while(!t.empty())
    {
        char x = t.back();
        v.push_back(x);
        t.pop_back();
    }
}
int compres(vector<char> &chars)
{
    vector<char> v;
    int i = 0;
    int count = 1;
    while (i < chars.size())
    {
        if (i+1<=chars.size()&&chars[i] == chars[i + 1])
        {
            // cout<<"jj"<<endl;
            count++;
        }
        else
        {
            v.push_back(chars[i]);
            if (count != 1)
            {
                string cht = to_string(count);
                for(char ch:cht)
                {
                    v.push_back(ch);
                }
                //push_count(v,count);
                //v.push_back(count + '0');
                count = 1;
            }
        }
        i++;
    }
    chars = v;
    return v.size();
}
int main(int argc, char const *argv[])
{
    //vector<char> v = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    //vector<char> v = {'a'};
    //vector<char> v = {'a','a'};
    vector<char> v = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    cout<<"input = ";
    for(char i:v)
    {
        cout<<i;
    }
    int n = compres(v);
    cout << endl;
    cout << "size = " << n << endl;
    cout<<"compres : ";
    for (char i : v)
    {
        cout << i;
    }
    int a=9;
    cout<<endl<<(int)&v[0];
    cout<<endl<<(int)&v[1];
    return 0;
}
