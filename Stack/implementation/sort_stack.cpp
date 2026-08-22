#include<iostream>
#include<stack>
using namespace std;
void insertatbottom(stack<int> &s,int x)
{
    // base case
    if(s.empty())
    {
        s.push(x);
        return;
    }

    // top element 
    int num = s.top();
    s.pop();

    // recursion call
    insertatbottom(s,x);
    s.push(num);
}
void sortedinsert(stack<int> &s,int x)
{
    // base case
    if (s.empty()||(!s.empty()&&s.top()<x))
    {
        s.push(x);
        return;
    }

    // top element
    int num = s.top();
    s.pop();

    // recursion call
    sortedinsert(s,x);
    s.push(num);
    
}
void sortstack(stack<int> &s)
{
    // base case
    if(s.empty())
    return;

    // top element
    int num = s.top();
    s.pop();

    // recursion
    sortstack(s);

    // insert at sorted oder
    sortedinsert(s,num);
}
void print(stack<int> s)
{
    cout<<"Top to bottom : ";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;
}
int main(int argc, char const *argv[])
{
    stack<int> input;
    input.push(3);
    input.push(-7);
    input.push(9);
    input.push(-2);
    input.push(5);

    cout<<"\nBefor sort stack : "<<endl;
    print(input);

    sortstack(input);
    cout<<"\nAfter sort stack : "<<endl;
    print(input);
    
    cout<<endl;

    return 0;
}
