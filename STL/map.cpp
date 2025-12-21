#include<iostream>
#include<map>
using namespace std;
int main(int argc, char const *argv[])
{
    map <int,string>m;
    m[1]="sukhdev";
    m[33]="dogiyal";
    m[2]="jodhpur";
    cout<<"map element : "<<endl;
    for(auto i:m)
    {
        cout<<i.first<<" ";
        cout<<i.second<<endl;
    }
    m.insert({5,"rajasthan"});
    m.erase(2);
    cout<<"map element : "<<endl;
    for(auto i:m)
    {
        cout<<i.first<<" ";
        cout<<i.second<<endl;
    }
    return 0;
}
