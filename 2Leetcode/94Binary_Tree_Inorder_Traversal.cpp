// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/description/
#include <iostream>
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

Node *buildtree(Node *root, int *data)
{
    static int i = -1;
    i = i + 1;
    root = new Node(data[i]);
    if (data[i] == -1)
        return NULL;
    root->left = buildtree(root->left, data);
    root->right = buildtree(root->right, data);
    return root;
}
void inorder(Node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // left child
    inorder(root->left, ans);

    // print
    ans.push_back(root->data);

    // right child
    inorder(root->right, ans);
}
void print(vector<int> arr)
{
    cout << "InOrder Traversal : ";
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
    root = buildtree(root, data);
    cout << endl;
    vector<int> ans;
    inorder(root, ans);
    print(ans);
    cout << endl;

    return 0;
}
/*
Tree :-

     1
   /   \
  3     5
 / \    /
7  11   17

InOrder Traversal : 7 3 11 1 17 5

*/
