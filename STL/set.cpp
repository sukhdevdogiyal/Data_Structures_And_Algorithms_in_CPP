#include<iostream>
#include<set>
using namespace std;
int main(int argc, char const *argv[])
{
    set<int>s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(1);
    s.insert(0);
    s.insert(0);
    s.insert(0);
    cout<<"Set : ";
    for(auto i:s)
    {
        cout<<i<<" ";
    }
    set<int>::iterator it = s.begin();
    ++it;
    s.erase(it);
    cout<<endl;
    for(auto i:s)
    {
        cout<<i<<" ";
    }

    cout<<endl<<*it;

    return 0;
}
