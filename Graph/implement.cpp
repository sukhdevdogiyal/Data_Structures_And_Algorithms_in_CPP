#include <iostream>
#include <map>
#include <list>
using namespace std;
class Graph
{
public:
    map<int, list<int>> adj;
    void addedge(int u, int v, bool direction)
    {
        // directon 0 -> undirected graph
        // directon 1 -> directed graph
        // create edge u to v
        adj[u].push_back(v);
        if (!direction)
            adj[v].push_back(u);
    }
    void printadjlist()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
                cout << j << ", ";
            cout << endl;
        }
    }
};
int main(int argc, char const *argv[])
{
    int n, m;
    cout << "Enter the number of Node : ";
    cin >> n; // 5
    cout << "Enter the number of Edge : ";
    cin >> m; // 6

    Graph g;
    cout << "Enter the edge :" << endl;
    /*
    0 1
    1 2
    2 3
    3 1
    3 4
    0 4*/
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v, 0);
    }
    cout << "Adjacency List Representation of Undirected Graph :" << endl;
    g.printadjlist();

    return 0;
}
/*
Adjacency List Representation of Undirected Graph :
0-> 1, 4,
1-> 0, 2, 3,
2-> 1, 3,
3-> 2, 1, 4,
4-> 3, 0,
*/