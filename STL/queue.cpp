#include<iostream>
#include<queue>
using namespace std;
int main(int argc, char const *argv[])
{
    queue<string>s;
    cout<<"s.size() = "<<s.size()<<endl;
    s.push("sukhdev");
    s.push("dogiyal");
    s.push("jodhpur");
    cout<<"s.front() = "<<s.front()<<endl;
    cout<<"s.size() = "<<s.size()<<endl;
    s.pop();
    cout<<"s.front() = "<<s.front()<<endl;
    
    cout<<"s.size() = "<<s.size()<<endl;
    cout<<"s.back() = "<<s.back()<<endl;
    return 0;
}
