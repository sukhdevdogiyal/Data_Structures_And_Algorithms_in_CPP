// There are n gas stations along a circular tour
#include <iostream>
#include <vector>
using namespace std;
int findstart(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int prevbal = 0, bal = 0, rear = 0, front = 0;
    while (rear < n)
    {
        bal = bal + gas[rear] - cost[rear];
        if (bal >= 0)
        {
            rear++;
        }
        else
        {
            prevbal += bal;
            bal = 0;
            rear++;
            front = rear;
        }
    }
    if (bal + prevbal >= 0)
    {
        return front;
    }
    else
    {
        return -1;
    }
}
int main(int argc, char const *argv[])
{
    vector<int> gas = {4, 5, 7, 4};
    vector<int> cost = {6, 6, 3, 5};
    cout << findstart(gas, cost);
    return 0;
}
