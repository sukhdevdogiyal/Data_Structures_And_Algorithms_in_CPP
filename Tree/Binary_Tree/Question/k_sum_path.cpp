// K sum path
// GFG
// Approch is not optimal
// optimal solution using hashmap+prefixsum
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildtree(int *data, int &i)
{
    i++;
    if (data[i] == -1)
        return NULL;

    Node *root = new Node(data[i]);
    root->left = buildtree(data, i);
    root->right = buildtree(data, i);
    return root;
}
void solve(Node *root, int k, int &count, vector<int> path)
{
    // base case
    if (root == NULL)
        return;
    // push node in path
    path.push_back(root->data);
    // left tree
    solve(root->left, k, count, path);
    // right tree
    solve(root->right, k, count, path);
    // process
    // find sum
    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }
}
int countallsumpaths(Node *root, int k)
{
    int count = 0;
    vector<int> path;
    solve(root, k, count, path);
    return count;
}
int main(int argc, char const *argv[])
{

    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    int j = -1;
    root = buildtree(data, j);
    cout << endl;
    int k = 3;
    cout << "Total No. of " << k << " sum path is : " << countallsumpaths(root, k);
    cout << endl;

    // tree 2
    int data1[] = {8, 4, 3, 3, -1, -1, -2, -1, -1, 2, -1, 1, -1, -1, 5, -1, 2, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    k = 7;
    cout << "Total No. of " << k << " sum path is : " << countallsumpaths(root1, k);
    cout << endl;

    // tree 3
    int data2[] = {1, 2, -1, 3, -1, 4, -1, 5, -1, -1, 9, 7, -1, -1, -1};
    Node *root2 = NULL;
    int k1 = -1;
    root2 = buildtree(data2, k1);
    k = 9;
    cout << "Total No. of " << k << " sum path is : " << countallsumpaths(root2, k);
    cout << endl;

    return 0;
}
/*
Tree 1 :-

     1
   /   \
  3     5
 / \   /
7  11 17

Tree 2 :-

       8
     /   \
    4     5
   / \     \
  3   2     2
 / \   \
3  -2   1

Tree 3 :-

       1
      /  \
     2    9
     \  /
     3  7
      \
       4
        \
         5


*/
