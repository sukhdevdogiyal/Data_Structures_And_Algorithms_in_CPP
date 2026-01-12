// Diameter of a binary tree
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
// Hight of binary tree
// pair.first = diameter
// pair.second = height
pair<int, int> diameter(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    // left child
    pair<int, int> left = diameter(root->left);
    // right child
    pair<int, int> right = diameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));             // diameter
    ans.second = max(left.second, right.second) + 1; // height
    return ans;
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
    cout << "Diameter of Binary Tree : " << diameter(root).first << endl;
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
