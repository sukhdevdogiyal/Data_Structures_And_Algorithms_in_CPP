#include<iostream>
//#include<algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    string s;
    getline(cin,s);
    int n=s.size();
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        if (s[i]==' '||s[i]=='\t')
        {
            s[i]='_';
        }
        
    }
    
    s.erase(s.begin()+s.find('.'),s.begin()+s.find('.')+2);
    cout<<endl<<s<<endl;
    cout<<endl;
    return 0;
}
