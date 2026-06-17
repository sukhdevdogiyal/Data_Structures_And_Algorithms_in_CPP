// Shortest path in Directed Acyclic Graph
// GFG
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <list>
#include <unordered_map>
using namespace std;
void toposort(int node, unordered_map<int, list<pair<int, int>>> &adj, vector<bool> &visited, stack<int> &s)
{
    visited[node] = true;
    for (auto i : adj[node])
    {
        if (!visited[i.first])
        {
            toposort(i.first, adj, visited, s);
        }
    }
    s.push(node);
}
vector<int> shortestPath(int V, vector<vector<int>> &edges, int src)
{
    // create adjancy list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        pair<int, int> p = make_pair(v, w);
        adj[u].push_back(p);
    }
    vector<bool> visited(V, 0);
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            toposort(i, adj, visited, s);
    }

    vector<int> dis(V, INT_MAX);
    dis[src] = 0;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (dis[top] != INT_MAX)
        {
            for (auto i : adj[top])
            {
                if (dis[top] + i.second < dis[i.first])
                {
                    dis[i.first] = dis[top] + i.second;
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (dis[i] == INT_MAX)
            dis[i] = -1;
    }

    return dis;
}
void print(vector<int> arr)
{
    cout << "Print all shortest distance to src : ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> edges = {{0, 1, 2},
                                 {0, 4, 1},
                                 {4, 5, 4},
                                 {4, 2, 2},
                                 {1, 2, 3},
                                 {2, 3, 6},
                                 {5, 3, 1}};
    int src = 0;
    int V = 6;
    cout << "Total Node : " << V << endl;
    cout << "source Node : " << src << endl;
    vector<int> dis = shortestPath(V, edges, src);
    print(dis);
    edges = {{0, 1, 2},
             {0, 2, 1}};
    src = 0;
    V = 4;
    cout << "Total Node : " << V << endl;
    cout << "source Node : " << src << endl;
    dis = shortestPath(V, edges, src);
    print(dis);
    return 0;
}
