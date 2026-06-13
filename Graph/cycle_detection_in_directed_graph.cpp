// Cycle detection in directed graph
#include <iostream>
#include <unordered_map>
#include <vector>
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
bool iscyclicdfs(int node, unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited)
{
    visited[node] = true;
    dfsvisited[node] = true;
    for (auto i : adjlist[node])
    {
        if (!visited[i])
        {
            bool ans = iscyclicdfs(i, adjlist, visited, dfsvisited);
            if (ans)
                return true;
        }
        else if (visited[i] && dfsvisited[i])
            return true;
    }
    dfsvisited[node] = false;
    return false;
}
bool isCyclic(int V, vector<vector<int>> &edges)
{
    // create adjancy list
    unordered_map<int, list<int>> adjlist;
    prepareAdjlist(edges, adjlist);
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool ans = iscyclicdfs(i, adjlist, visited, dfsvisited);
            if (ans)
                return true;
        }
    }
    return false;
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
    cout<<"Directed Graph Cycle present : "<<isCyclic(8, edge)<<endl;
    
    edge = {{1, 2},
    {2, 3},
    {3, 7},
    {3, 8},
    {8, 7},
    {2, 4},
    {4, 5},
    {5, 6},
    {6, 4}};
    cout<<"Directed Graph Cycle present : "<<isCyclic(9, edge)<<endl;
    return 0;
}
