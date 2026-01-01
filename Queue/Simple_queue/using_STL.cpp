#include<iostream>
#include<queue>
using namespace std;
int main(int argc, char const *argv[])
{
    queue<int> q;
    cout<<"Push 10 in queue "<<endl;
    q.push(10);
    cout<<"Push 20 in queue "<<endl;
    q.push(20);
    cout<<"Push 30 in queue "<<endl;
    q.push(30);
    cout<<"Pop into queue "<<endl;
    q.pop();
    cout<<"front : "<<q.front()<<endl;
    cout<<"back : "<<q.back()<<endl;
    cout<<"size of queue : "<<q.size();
    return 0;
}
