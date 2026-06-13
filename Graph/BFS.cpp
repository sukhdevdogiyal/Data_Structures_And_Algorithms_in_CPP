#include <iostream>
#include <vector>
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
        adjlist[v].push_back(u);
    }
}
void solve(int node, unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited, vector<int> &ans)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int front = q.front();
        ans.push_back(front);
        q.pop();
        for (auto i : adjlist[front])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
vector<int> dfs(int vertex, vector<vector<int>> &edge)
{
    // create adjacency list
    unordered_map<int, list<int>> adjlist;
    prepareAdjlist(edge, adjlist);

    unordered_map<int, bool> visited;
    vector<int> ans;
    // handel disconnected componts
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            solve(i, adjlist, visited, ans);
        }
    }
    return ans;
}
void print(vector<int> &arr)
{
    cout << "BFS oder : ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
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
    vector<int> ans = dfs(8, edge);
    print(ans);
    return 0;
}
