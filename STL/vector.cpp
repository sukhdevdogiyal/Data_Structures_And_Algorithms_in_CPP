#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> v;
    cout<<"Create a vactor"<<endl;
    cout << "capacity of vector v = " << v.capacity() << endl;
    cout << "size of vector v = " << v.size() << endl;
    cout<<"Insert a value in vactor :"<<endl;
    for (int i = 1; i <= 5; i++)
    {
        v.push_back(i);
        cout << "capacity of vector v = " << v.capacity() << endl;
        cout << "size of vector v = " << v.size() << endl;
    }
    cout<<"Address of all vector element : ";
    for (int i = 0; i < 5; i++)
    {
        cout<<(int)&v[i]<<" ";
    }
    
    cout<<"\nElement of vector : ";
    for (int j:v)
    {
        cout<<j<<" ";
    }
    cout<<endl;
    cout<<"v.at(2) = "<<v.at(2)<<endl;
    cout<<"v.front() = "<<v.front()<<endl;
    cout<<"v.back() = "<<v.back()<<endl;
    cout<<"pop_back() "<<endl;
    v.pop_back();
    cout<<"v.back() = "<<v.back()<<endl;
    cout << "capacity of vector v = " << v.capacity() << endl;
    cout << "size of vector v = " << v.size() << endl;
    cout<<"v.empty() = "<<v.empty()<<endl;
    cout<<"v.clear()"<<endl;
    v.clear();
    cout<<"v.empty() = "<<v.empty()<<endl;
    cout << "capacity of vector v = " << v.capacity() << endl;
    cout << "size of vector v = " << v.size() << endl;
    auto k=v.begin();
    cout<<"*v.begin() = ";
    cout<<*k<<endl<<endl;

    cout<<"  -: Vector a :- "<<endl;
    vector<int>a(3,5);
    cout<<"vector a = ";
    for (int j:a)
    {
        cout<<j<<" ";
    }
    cout<<endl;
    cout << "capacity of vector v = " << a.capacity() << endl;
    cout << "size of vector v = " << a.size() << endl;
    cout<<endl;
    
    cout<<"  -: Vector b :- "<<endl;
    vector<int>b(a);
    cout<<"b.push_back(8)"<<endl;
    b.push_back(8);
    cout<<"vector = ";
    for (int j:b)
    {
        cout<<j<<" ";
    }
    cout<<endl;
    cout<<"b.pop_back()"<<endl;
    b.pop_back();
    cout << "capacity of vector v = " << b.capacity() << endl;
    cout << "size of vector v = " << b.size() << endl;
    cout<<"b[5] = "<<b[5]<<endl;
    cout<<"b.shrink_to_fit() ";
    b.shrink_to_fit();
    cout<<endl;
    cout << "capacity of vector v = " << b.capacity() << endl;
    cout << "size of vector v = " << b.size() << endl;
    return 0;
}
