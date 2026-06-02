// Morris traversal
// Inorder Traversal
// GFG
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
// find the predecessor of current node
Node *findPredecessor(Node *current)
{
    Node *temp = current->left;
    while (temp->right != NULL && temp->right != current)
        temp = temp->right;
    return temp;
}
void inoder(Node *root)
{
    Node *current = root;
    while (current)
    {
        if (current->left == NULL) // left not exists print current
        {
            cout << current->data << " "; // print
            current = current->right;     // update current
        }
        else // left exists
        {
            // find predecessor
            Node *predecessor = findPredecessor(current);
            // temp link create
            if (predecessor->right == NULL)
            {
                predecessor->right = current; // link
                current = current->left;      // update current
            }
            // temp link remove
            else
            {
                predecessor->right = NULL;    // remove link
                cout << current->data << " "; // print
                current = current->right;     // update
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    int j = -1;
    root = buildtree(data, j);
    cout << "InOrder Traversal : ";
    inoder(root);
    cout << endl
         << endl;

    // tree 2
    int data1[] = {8, 4, 3, 3, -1, -1, -2, -1, -1, 2, -1, 1, -1, -1, 5, -1, 2, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    cout << "InOrder Traversal : ";
    inoder(root1);
    cout << endl
         << endl;

    // tree 3
    int data2[] = {1, 2, -1, 3, -1, 4, -1, 5, -1, -1, 9, 7, -1, -1, -1};
    Node *root2 = NULL;
    int k1 = -1;
    root2 = buildtree(data2, k1);
    cout << "InOrder Traversal : ";
    inoder(root2);
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
