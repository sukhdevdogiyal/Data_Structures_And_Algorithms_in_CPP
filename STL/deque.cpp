#include<iostream>
#include<deque>
using namespace std;
int main(int argc, char const *argv[])
{
    deque<int>d;
    d.push_back(9);
    d.push_back(45);
    d.push_back(6);
    d.push_back(4);
    d.push_front(2);
    cout<<"d.size() = "<<d.size()<<endl;
    //cout<<"d.size() = "<<d.capacity()<<endl;
    cout<<"Deque element : ";
    for(int i:d)
    {
        cout<<i<<" ";
    }cout<<endl;
    cout<<"d.at(2) = "<<d.at(2)<<endl;
    cout<<"d.erase(d.begin()+1,d.begin()+3)"<<endl;
    d.erase(d.begin()+1,d.begin()+3);
    cout<<"Deque element : ";
    for(int i:d)
    {
        cout<<i<<" ";
    }cout<<endl;
    cout<<"d.pop_back()"<<endl;
    d.pop_back();
    cout<<"Deque element : ";
    for(int i:d)
    {
        cout<<i<<" ";
    }cout<<endl;
    cout<<"d.pop_front()"<<endl;
    d.pop_front();
    cout<<"Deque element : ";
    for(int i:d)
    {
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}
