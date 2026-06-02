// GFG
// Binary Tree from Inorder and Preorder
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
int findnode(vector<int> &inorder, int val, int s, int e)
{
    // cout<<s<<" ";
    while (s <= e)
    {
        if (inorder[s] == val)
            return s;
        s++;
    }
}
Node *solve(vector<int> &inorder, vector<int> &preorder, int &i, int s, int e)
{
    // base case
    if (s > e)
        return NULL;

    // root node
    Node *root = new Node(preorder[i]);
    // find position of element in inorder
    int p = findnode(inorder, preorder[i], s, e);
    i++;
    // recursion call
    // left part s to p-1
    root->left = solve(inorder, preorder, i, s, p - 1);
    // right par p+1 to e
    root->right = solve(inorder, preorder, i, p + 1, e);
    return root;
}
Node *buildTree(vector<int> &inorder, vector<int> &preorder)
{
    int i = 0;
    return solve(inorder, preorder, i, 0, inorder.size() - 1);
}
void printinorder(Node *root)
{
    if (root == NULL)
        return;
    printinorder(root->left);
    cout << root->data << " ";
    printinorder(root->right);
}
int main(int argc, char const *argv[])
{
    vector<int> preorder = {0, 1, 3, 4, 2, 5};
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    Node *root = buildTree(inorder, preorder);
    cout << "Inorder : ";
    printinorder(root);
    return 0;
}
