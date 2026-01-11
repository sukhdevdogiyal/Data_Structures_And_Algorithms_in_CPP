#include <iostream>
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
void inoder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // left child
    inoder(root->left);

    // print
    cout << root->data << " ";

    // right child
    inoder(root->right);
}
// Hight of binary tree
int height(Node *root)
{
    // leaf node
    if (root->left == NULL && root->right == NULL)
        return 0;

    int left = 0, right = 0;
    // left child
    if (root->left != NULL)
    {
        left = height(root->left) + 1;
    }

    // right child
    if (root->right != NULL)
        right = height(root->right) + 1;
    return max(left, right);
}
int main(int argc, char const *argv[])
{
    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    int j = -1;
    root = buildtree(data, j);
    cout << endl;
    cout << "InOrder Traversal : ";
    inoder(root);
    cout << endl;
    cout << "Height of Binary Tree : " << height(root) << endl;
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
