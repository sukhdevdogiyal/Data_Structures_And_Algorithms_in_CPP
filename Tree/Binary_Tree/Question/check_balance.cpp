// check balance tree
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
// check balance of binary tree
// pair.first = balance
// pair.second = height
pair<bool, int> slove(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = slove(root->left);
    pair<bool, int> right = slove(root->right);

    pair<bool, int> ans;
    ans.first = left.first && right.first && abs(left.second - right.second) <= 1;
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
void isBalance(Node *root)
{
    if (slove(root).first)
        cout << "Tree is Balance" << endl;
    else
        cout << "Tree is Not Balance" << endl;
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
    isBalance(root);
    cout << endl;

    // tree 2
    int data1[] = {1, 2, 3, 4, -1, -1, -1, -1, 5, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    cout << "InOrder Traversal : ";
    inoder(root1);
    cout << endl;
    isBalance(root1);
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
