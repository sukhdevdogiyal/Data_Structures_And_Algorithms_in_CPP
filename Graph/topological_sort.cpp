#include <iostream>
#include <vector>
#include <stack>
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
void dfs(int node, unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited, stack<int> &st)
{
    visited[node] = true;
    for (auto nbr : adjlist[node])
    {
        if (!visited[nbr])
        {
            dfs(nbr, adjlist, visited, st);
        }
    }
    st.push(node);
}
vector<int> toposort(int vertex, vector<vector<int>> &edge)
{
    // create adjacency list
    unordered_map<int, list<int>> adjlist;
    prepareAdjlist(edge, adjlist);

    unordered_map<int, bool> visited;
    stack<int> st;
    // handel disconnected componts
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            dfs(i, adjlist, visited, st);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
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
    ans = toposort(4, edge);
    print(ans);
    return 0;
}
