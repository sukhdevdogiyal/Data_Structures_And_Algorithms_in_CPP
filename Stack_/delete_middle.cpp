#include<iostream>
#include<stack>
using namespace std;
void deletemiddle(stack<int>&s,int count,int size)
{
    if (count==size/2)
    {
        s.pop();
        return;
    }

    int element = s.top();
    s.pop();
    deletemiddle(s,count+1,size);
    s.push(element);
    
}
int main(int argc, char const *argv[])
{
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    deletemiddle(s1,0,s1.size());
    cout<<"After delete middle : ";
    while (!s1.empty())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }
    
    stack<int> s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    deletemiddle(s2,0,s2.size());
    cout<<"\nAfter delete middle : ";
    while (!s2.empty())
    {
        cout<<s2.top()<<" ";
        s2.pop();
    }
    return 0;
}
