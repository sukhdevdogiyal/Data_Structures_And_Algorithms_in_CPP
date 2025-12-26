#include<iostream>
#include<stack>
using namespace std;
int main(int argc, char const *argv[])
{
    // create stack
    stack<int> s;
    
    // push operation
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    // top
    cout<<"top1 = "<<s.top()<<endl;
    
    // pop operation
    s.pop();
    
    cout<<"top2 = "<<s.top()<<endl;

    // empty
    if(s.empty())
    cout<<"stack is empty"<<endl;
    else
    cout<<"stack is not empty"<<endl;
    cout<<"size of stack : "<<s.size();
    return 0;
}
