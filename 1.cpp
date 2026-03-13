#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<string>v={"afa","af"};
    string a = v[0];
    string b = v[1];
    //cout<<(a==b);
    for (int i = 0; i < 10000; i++)
    {
        cout<<i<<",";
    }
    
    return 0;
}
