#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;
void prepareAdjlist(vector<vector<int>> &edge, unordered_map<int, list<int>> &adjlist)
{
    for (int i = 0; i < edge.size(); i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        adjlist[u].push_back(v);
    }
}
vector<int> toposort(int vertex, vector<vector<int>> &edge)
{
    // create adjacency list
    unordered_map<int, list<int>> adjlist;
    prepareAdjlist(edge, adjlist);

    vector<int> indegree(vertex, 0);
    for (int i = 0; i < vertex; i++)
    {
        for (auto j : adjlist[i])
        {
            indegree[j]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < vertex; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto nbr : adjlist[front])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }
    return ans;
}
void print(vector<int> &arr)
{
    cout << "Topological Sort of Graph : ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> edge;
    edge = {{0, 3},
            {3, 1},
            {1, 4},
            {1, 2},
            {5, 6},
            {6, 7},
            {5, 7}};
    vector<int> ans = toposort(8, edge);
    print(ans);
    cout << endl;
    edge = {{0, 3},
            {3, 1},
            {1, 4},
            {1, 2}};
    ans = toposort(5, edge);
    print(ans);
    return 0;
}
