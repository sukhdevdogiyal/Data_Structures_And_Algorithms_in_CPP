// Shortest Path in Undirected Graph
// GFG
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;
vector<int> shortestPath(int V, vector<vector<int>> &edges, int src)
{
    // create adjancy list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dis(V, -1);
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto i : adj[front])
        {
            if (dis[i] == -1)
            {
                dis[i] = dis[front] + 1;
                q.push(i);
            }
        }
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
    vector<vector<int>> edges = {{0, 1},
                                 {0, 3},
                                 {1, 2},
                                 {3, 4},
                                 {4, 5},
                                 {2, 6},
                                 {5, 6},
                                 {6, 7},
                                 {6, 8},
                                 {7, 8}};
    int src = 0;
    int V = 4;
    cout << "Total Node : " << V << endl;
    cout << "source Node : " << src << endl;
    vector<int> dis = shortestPath(9, edges, src);
    print(dis);
    edges = {
        {0, 3},
        {1, 3},
    };
    src = 3;
    V = 4;
    cout << "Total Node : " << V << endl;
    cout << "source Node : " << src << endl;
    dis = shortestPath(4, edges, src);
    print(dis);
    return 0;
}
