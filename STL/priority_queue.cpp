#include<iostream>
#include<queue>
using namespace std;
int main(int argc, char const *argv[])
{
    priority_queue<int> maxi;
    maxi.push(34);
    maxi.push(54);
    maxi.push(344);
    cout<<"Max Heap : ";
    for (int i = 1; i <= 3; i++)
    {
        cout<<maxi.top()<<" ";
        maxi.pop();
        
    }
    priority_queue<int,vector<int>,greater<int>>min;
    min.push(34);
    min.push(474);
    min.push(0);
    cout<<endl<<"Min Heap : ";
    
    for (int i = 1; i <= 3; i++)
    {
        cout<<min.top()<<" ";
        min.pop();
    }
    
    return 0;
}
