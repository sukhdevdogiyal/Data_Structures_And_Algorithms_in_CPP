#include <iostream>
#include <queue>
using namespace std;
int main(int argc, char const *argv[])
{
    deque<int> q;
    cout << "push front element 10 in queue " << endl;
    q.push_front(10);
    cout << "push front element 20 in queue " << endl;
    q.push_front(20);
    cout << "push back element 30 in queue " << endl;
    q.push_back(30);
    cout << "front element : " << q.front() << endl;
    cout << "back element : " << q.back() << endl;
    cout << "pop front element  " << endl;
    q.pop_front();
    cout << "front element : " << q.front() << endl;
    cout << "pop back element  " << endl;
    q.pop_back();
    cout << "back element : " << q.front() << endl;

    return 0;
}
