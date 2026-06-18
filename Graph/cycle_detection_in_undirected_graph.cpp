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
bool solve(int node, int parent, unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    for (auto nbr : adjlist[node])
    {
        if (visited[nbr] && parent != nbr)
        {
            return true;
        }
        else if (!visited[nbr])
        {
            bool ans = solve(nbr, node, adjlist, visited);
            if (ans)
                return true;
        }
    }
    return false;
}
bool cycledetection(int vertex, vector<vector<int>> &edge)
{
    // create adjacency list
    unordered_map<int, list<int>> adjlist;
    prepareAdjlist(edge, adjlist);

    unordered_map<int, bool> visited;
    // handel disconnected componts
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bool ans = solve(i, -1, adjlist, visited);
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
    cout << "Cycle Detection in UnDirected Graph : " << cycledetection(8, edge);
    cout << endl;
    edge = {{0, 3},
            {3, 1},
            {1, 4},
            {1, 2}};
    cout << "Cycle Detection in UnDirected Graph : " << cycledetection(8, edge);
    return 0;
}
