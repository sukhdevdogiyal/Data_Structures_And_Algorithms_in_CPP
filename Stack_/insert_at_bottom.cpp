#include<iostream>
#include<stack>
using namespace std;
int main(int argc, char const *argv[])
{
    stack<int> input;
    input.push(2);
    input.push(3);
    input.push(4);
    input.push(5);

    int x =1;
    stack<int> s;
    while (!input.empty())
    {
        s.push(input.top());
        input.pop();
    }
    input.push(x);
    while(!s.empty())
    {
        input.push(s.top());
        s.pop();
    }
    cout<<"After add element : "<<endl; 
    while(!input.empty())
    {
        cout<<input.top()<<" ";
        input.pop();
    }
    
    return 0;
}
