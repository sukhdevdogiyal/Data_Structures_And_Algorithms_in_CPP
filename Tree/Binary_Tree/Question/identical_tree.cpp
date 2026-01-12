// identical tree
// determine id two tree are identical
// GFG
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
// identical tree
bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;
    if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL))
        return false;

    // left tree
    bool left = isIdentical(r1->left, r2->left);
    // right tree
    bool right = isIdentical(r1->right, r2->right);
    return left && right && r1->data == r2->data;
}
void check(Node *r1, Node *r2)
{
    if (isIdentical(r1, r2))
        cout << "Tree is Identical" << endl;
    else
        cout << "Tree is Not Identical" << endl;
}
int main(int argc, char const *argv[])
{
    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    int j = -1;
    root = buildtree(data, j);
    cout << endl;
    cout << "Tree 1 InOrder Traversal : ";
    inoder(root);
    cout << endl;

    // tree 2
    int data1[] = {1, 2, 3, 4, -1, -1, -1, -1, 5, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    cout << "Tree 2 InOrder Traversal : ";
    inoder(root1);
    cout << endl;
    cout << "Tree 1&2 : ";
    check(root, root1);
    cout << "Tree 1&1 : ";
    check(root, root);

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
