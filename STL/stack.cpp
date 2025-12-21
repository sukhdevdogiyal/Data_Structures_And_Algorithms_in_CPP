#include<iostream>
#include<stack>
using namespace std;
int main(int argc, char const *argv[])
{
    stack<string>s;
    cout<<"s.size() = "<<s.size()<<endl;
    s.push("sukhdev");
    s.push("dogiyal");
    s.push("jodhpur");
    cout<<"s.top() = "<<s.top()<<endl;
    cout<<"s.size() = "<<s.size()<<endl;
    s.pop();
    
    cout<<"s.size() = "<<s.size()<<endl;
    cout<<"s.top() = "<<s.top()<<endl;
    return 0;
}
