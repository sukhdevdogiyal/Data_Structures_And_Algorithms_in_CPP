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
void preoder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // print
    cout << root->data << " ";

    // left child
    preoder(root->left);

    // right child
    preoder(root->right);
}
int main(int argc, char const *argv[])
{
    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    root = buildtree(root, data);
    cout << endl;
    cout << "PreOrder Traversal : ";
    preoder(root);
    cout << endl;
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

PreOrder Traversal : 1 3 7 11 5 17

*/
