#include <iostream>
using namespace std;

// Node
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

// Binary Tree build
// Return Root node
Node *bulidtree(Node *root)
{
    cout << "Enter the data : ";
    int data;
    cin >> data;
    root = new Node(data);

    // condition for leaf Node
    if (data == -1)
        return NULL;

    // left node
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = bulidtree(root->left);

    // right node
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = bulidtree(root->right);

    return root;
}
int main(int argc, char const *argv[])
{
    Node *root = NULL;
    root = bulidtree(root);
    return 0;
}
