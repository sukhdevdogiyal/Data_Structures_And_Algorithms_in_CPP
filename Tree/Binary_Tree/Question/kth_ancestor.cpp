// Kth Ancestor
// GFG
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
int solve(Node *root, int k, int node, int &ans)
{
    if (root == NULL)
        return -1;
    // find node
    if (root->data == node)
        return 1;
    int left = solve(root->left, k, node, ans);
    int right = solve(root->right, k, node, ans);
    // find kth ancestor of node
    if (left == k || right == k)
    {
        ans = root->data;
        return -1;
    }
    // child tree find node
    if (left != -1)
    {
        return left + 1;
    }
    if (right != -1)
    {
        return right + 1;
    }
    // not find ancestor
    return -1;
}
int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    solve(root, k, node, ans);
    return ans;
}

int main(int argc, char const *argv[])
{

    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    int j = -1;
    root = buildtree(data, j);
    cout << endl;
    int k = 2;
    int node = 11;
    cout << k << "th Ancestor of " << node << " : " << kthAncestor(root, k, node) << endl;
    cout << endl;

    // tree 2
    int data1[] = {8, 4, 3, 3, -1, -1, -2, -1, -1, 2, -1, 1, -1, -1, 5, -1, 2, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    k = 5;
    node = 3;
    cout << k << "th Ancestor of " << node << " : " << kthAncestor(root1, k, node) << endl;
    cout << endl;

    // tree 3
    int data2[] = {1, 2, -1, 3, -1, 4, -1, 5, -1, -1, 9, 7, -1, -1, -1};
    Node *root2 = NULL;
    int k1 = -1;
    root2 = buildtree(data2, k1);
    k = 2;
    node = 4;
    cout << k << "th Ancestor of " << node << " : " << kthAncestor(root2, k, node) << endl;
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
