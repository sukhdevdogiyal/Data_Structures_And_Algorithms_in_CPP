// Lowest Common Ancestor in a Binary Tree
// GFG

#include <iostream>
#include <queue>
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
Node *lca(Node *root, int n1, int n2)
{
    // base case
    if (root == NULL)
        return NULL;
    // find n1 or n2 return root
    if (root->data == n1 || root->data == n2)
        return root;
    // left tree
    Node *lefttree = lca(root->left, n1, n2);
    // right tree
    Node *righttree = lca(root->right, n1, n2);

    // process
    // one left tree and second right tree then ancestor is root
    if (lefttree && righttree)
        return root;
    // left not null return left else return right
    return lefttree != NULL ? lefttree : righttree;
}
int main(int argc, char const *argv[])
{

    int data[] = {1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
    Node *root = NULL;
    int j = -1;
    root = buildtree(data, j);
    cout << endl;
    int n1 = 7,n2=5;
    cout<<"Lowest common Ancestor of "<<n1<<" and "<<n2<<" is : "<<lca(root,n1,n2)->data;
    cout << endl;
    
    // tree 2
    int data1[] = {1, 2, -1, -1, 5, 6, 8, -1, -1, -1, 7, -1, -1};
    Node *root1 = NULL;
    int i = -1;
    root1 = buildtree(data1, i);
    n1 = 8,n2=7;
    cout<<"Lowest common Ancestor of "<<n1<<" and "<<n2<<" is : "<<lca(root1,n1,n2)->data;
    cout << endl;
    
    // tree 3
    int data2[] = {1, 2, -1, 3, -1, 4, -1, 5, -1, -1, 9, 7, -1, -1, -1};
    Node *root2 = NULL;
    int k = -1;
    root2 = buildtree(data2, k);
    n1 = 4,n2=3;
    cout<<"Lowest common Ancestor of "<<n1<<" and "<<n2<<" is : "<<lca(root2,n1,n2)->data;
    cout << endl;
    
    return 0;
}
/*
Tree 1 :-

     1
   /   \
  3     5
 / \   /
7  11 17

Tree 2 :-

       1
     /   \
    2     5
         / \
        6   7
       /
      8

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


*/
