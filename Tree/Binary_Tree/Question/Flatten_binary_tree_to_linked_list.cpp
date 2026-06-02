// Flatten binary tree to linked list
// GFG
// https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1
// Morris traversal
// T.C. = O(n)
// S.C. = O(1)
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

// Approch #1
// S.C = O(n)
Node *solve(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL)
        return root;
    if (root->left)
    {
        Node *last = solve(root->left);
        last->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return solve(last->right);
    }
    else
    {
        return solve(root->right);
    }
}
void flatten1(Node *root)
{
    solve(root);
}

// Approch #2
// S.C. = O(1)
// find the predecessor of current node
Node *findPredecessor(Node *current)
{
    Node *temp = current;
    temp = temp->left;
    while (temp->right)
        temp = temp->right;
    return temp;
}
void flatten(Node *root)
{
    Node *current = root;
    while (current != NULL)
    {
        if (current->left != NULL)
        {
            Node *predecessor = findPredecessor(current);
            predecessor->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}
void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print(root->right);
}
int main(int argc, char const *argv[])
{
    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    int j = -1;
    root = buildtree(data, j);
    cout << "InOrder Traversal : ";
    // flatten1(root);
    flatten(root);
    print(root);
    // inoder(root);
    cout << endl
         << endl;

    // tree 2
    int data1[] = {8, 4, 3, 3, -1, -1, -2, -1, -1, 2, -1, 1, -1, -1, 5, -1, 2, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    cout << "InOrder Traversal : ";
    // flatten1(root1);
    flatten(root1);
    print(root1);
    // inoder(root1);
    cout << endl
         << endl;

    // tree 3
    int data2[] = {1, 2, -1, 3, -1, 4, -1, 5, -1, -1, 9, 7, -1, -1, -1};
    Node *root2 = NULL;
    int k1 = -1;
    root2 = buildtree(data2, k1);
    cout << "InOrder Traversal : ";
    // flatten1(root2);
    flatten(root2);
    print(root2);

    cout << endl
         << endl;

    return 0;
}
/*
Tree 1 :-

     1
   /   \
  3     5
 / \   /
7  11 17
InOrder Traversal : 7 3 11 1 17 5

Tree 2 :-

       8
     /   \
    4     5
   / \     \
  3   2     2
 / \   \
3  -2   1
InOrder Traversal : 3 3 -2 4 2 1 8 5 2

Tree 3 :-

       1
      /  \
     2    9
     \  /
     3  7
      \
       4
        \
         5
InOrder Traversal : 2 3 4 5 1 7 9

*/
