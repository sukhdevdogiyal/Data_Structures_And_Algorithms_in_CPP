// Kth Ancestor in a Tree
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
    if (root->data == node)
        return 1;
    int left = solve(root->left, k, node, ans);
    int right = solve(root->right, k, node, ans);
    if (left == k)
    {
        ans = root->data;
        return -1;
    }
    if (right == k)
    {
        ans = root->data;
        return -1;
    }

    if (left != -1)
    {
        return left + 1;
    }
    if (right != -1)
    {
        return right + 1;
    }
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
    cout << "Kth Ancestor in a Tree : " << kthAncestor(root, 2, 7) << endl;
    cout << endl;

    // tree 2
    int data1[] = {1, 2, -1, -1, 5, 6, 8, -1, -1, -1, 7, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    cout << "Kth Ancestor in a Tree : " << kthAncestor(root1, 3, 6) << endl;
    cout << endl;

    // tree 3
    int data2[] = {1, 2, -1, 3, -1, 4, -1, 5, -1, -1, 9, 7, -1, -1, -1};
    Node *root2 = NULL;
    int k = -1;
    root2 = buildtree(data2, k);
    cout << "Kth Ancestor in a Tree : " << kthAncestor(root2, 2, 4) << endl;
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

       1
     /   \
    2     5
         / \
        6   7
       /
      8

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
