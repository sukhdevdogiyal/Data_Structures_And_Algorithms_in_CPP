#include<iostream>
#include<unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
    // creation
    unordered_map<string,int>m;

    // insertion
    // 1
    pair<string,int> p = make_pair("love",2);
    m.insert(p);

    // 2 
    pair<string,int> p2("baby",3);
    m.insert(p2);

    // 3
    m["mera"] = 1;
    // update
    m["mera"] = 4;
    // searching
    cout<<"m[\"mera\"] : "<<m["mera"]<<endl;
    cout<<"m.at(\"mera\") : "<<m.at("mera")<<endl;
    // if not present create new key and set default 0
    cout<<"suk not in map m[\"suk\"] : "<<m["suk"]<<endl;
    
    // if not present throw exception : 'std::out_of_range'
    // cout<<"su not in map m[\"su\"] : "<<m.at("su")<<endl;

    // size
    cout<<"size of map : "<<m.size()<<endl;
    
    // present
    cout<<"count of l in map : "<<m.count("l")<<endl; // not create entry
    
    // erase 
    cout<<"erase the suk "<<endl;
    m.erase("suk");
    cout<<"size of map : "<<m.size()<<endl;
    cout<<"map all key and value:"<<endl;
    for (auto i : m)
    {
        cout<<i.first<<" : "<<i.second<<endl;
    }
    // using iterator
    unordered_map<string,int> :: iterator it = m.begin();
    cout<<"using iterator : "<<endl;
    while (it!=m.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    
    
    return 0;
}
