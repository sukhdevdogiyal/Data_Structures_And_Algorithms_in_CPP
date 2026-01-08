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
void postoder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // left child
    postoder(root->left);

    // right child
    postoder(root->right);

    // print
    cout << root->data << " ";
}
int main(int argc, char const *argv[])
{
    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    root = buildtree(root, data);
    cout << endl;

    cout << "PostOrder Traversal : ";
    postoder(root);
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

PostOrder Traversal : 7 11 3 17 5 1

*/
