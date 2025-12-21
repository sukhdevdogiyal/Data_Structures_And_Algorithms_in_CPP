#include <iostream>
#include <list>
using namespace std;
int main(int argc, char const *argv[])
{
    list<int> l;
    l.push_back(90);
    l.push_back(92);
    l.push_back(903);
    cout << "l.size() = " << l.size() << endl;
    // cout<<"l.capacity()"<<l.capacity();  //list is double linked list
    l.push_front(37);
    l.push_front(337);
    cout << "l.size() = " << l.size() << endl;
    cout<<"list element = ";
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    cout<<"l.erase(l.begin())"<<endl;
    l.erase(l.begin());
    cout<<"*l.begin() = "<<*l.begin()<<endl;
    cout<<"list element = ";
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
   // l.erase(l.end());
    cout<<"*l.end() = "<<*l.end()<<endl;
    // for (int i : l)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout<<"l.at(2) = "<<l.at(2);
    
    return 0;
}
