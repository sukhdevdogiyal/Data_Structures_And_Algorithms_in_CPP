// Boundry tree traversal
// GFG
#include <iostream>
#include <vector>
#include <queue>
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
void leftpart(Node *root, vector<int> &ans)
{
    // base case
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    ans.push_back(root->data);
    if (root->left)
        leftpart(root->left, ans);
    else
        leftpart(root->right, ans);
}
void leafnode(Node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    leafnode(root->left, ans);
    leafnode(root->right, ans);
}
void rightpart(Node *root, vector<int> &ans)
{
    // base case
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (root->right)
        rightpart(root->right, ans);
    else
        rightpart(root->left, ans);
    ans.push_back(root->data); // reverse oder
}
vector<int> boundry(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    // push root node
    ans.push_back(root->data);
    // left part
    leftpart(root->left, ans);
    // root ke left side leaf node // because one one node in tree
    leafnode(root->left, ans);
    // root ke right side leaf node
    leafnode(root->right, ans);
    // right part reverse oder
    rightpart(root->right, ans);
    return ans;
}
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    int j = -1;
    root = buildtree(data, j);
    cout << endl;
    cout << "Tree 1 Boundry Traversal : ";
    vector<int> ans = boundry(root);
    print(ans);
    cout << endl;

    // tree 2
    int data1[] = {1, 2, 3, 4, -1, -1, -1, -1, 5, 6, -1, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    cout << "Tree 2 Boundry Traversal : ";
    ans = boundry(root1);
    print(ans);
    cout << endl;

    // tree 3
    int data2[] = {1, -1, 2, -1, 3, -1, 4, -1, -1}; //, 6, -1, -1, -1};
    Node *root2 = NULL;
    int k = -1;
    root2 = buildtree(data2, k);
    cout << "Tree 3 Boundry Traversal : ";
    ans = boundry(root2);
    print(ans);
    cout << endl;

    return 0;
}
/*
Tree 1 :-

     1
   /   \
  3     5
 / \    /
7  11   17

InOrder Traversal : 7 3 11 1 17 5

Tree 2 :-

       1
     /   \
    2     5
   /     /
  3     6
 /
4

Tree 3
 1
  \
   2
    \
     3
      \
       4
*/
