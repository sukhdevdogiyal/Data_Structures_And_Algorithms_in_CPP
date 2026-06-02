// GFG
// Binary Tree from Inorder and Postorder
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
int findposition(vector<int> &inorder, int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (inorder[i] == element)
            return i;
    }
}
Node *solve(vector<int> &inorder, vector<int> &postorder, int &index, int s, int e, int n)
{
    // base case
    if (s > e || index < 0)
        return NULL;
    // root node
    int element = postorder[index--];
    Node *root = new Node(element);

    // find postion
    int position = findposition(inorder, element, n);
    // right part
    root->right = solve(inorder, postorder, index, position + 1, e, n);
    root->left = solve(inorder, postorder, index, s, position - 1, n);
    return root;
}
Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    // code here
    int n = inorder.size();
    int index = n - 1;
    return solve(inorder, postorder, index, 0, n - 1, n);
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
    vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1};
    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    Node *root = buildTree(inorder, postorder);
    cout << "Inorder : ";
    printinorder(root);
    return 0;
}
